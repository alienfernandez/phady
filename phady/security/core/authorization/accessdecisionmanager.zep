/*
+------------------------------------------------------------------------+
| Phady Framework                                                        |
+------------------------------------------------------------------------+
| Copyright (c) 2015                                                     |
+------------------------------------------------------------------------+
| Phady Framework is a complement of Phalcon Framework                   |
|                                                                        |
+------------------------------------------------------------------------+
| Authors: Alien fernandez Fuentes <alienfernandez85@gmail.com>          |
+------------------------------------------------------------------------+
*/

namespace Phady\Security\Core\Authorization;

use Phady\Security\Core\Authorization\AccessDecisionManagerInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Authorization\Voter\VoterInterface;

/**
  * @class Phady\Security\Core\Authorization\AccessDecisionManager
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AccessDecisionManager implements AccessDecisionManagerInterface
{
    const STRATEGY_AFFIRMATIVE = "affirmative";
    const STRATEGY_CONSENSUS = "consensus";
    const STRATEGY_UNANIMOUS = "unanimous";

    private voters;
    private strategy;
    private allowIfAllAbstainDecisions;
    private allowIfEqualGrantedDeniedDecisions;

    /**
     * Constructor.
     *
     * @param VoterInterface[] voters                             An array of VoterInterface instances
     * @param string           strategy                           The vote strategy
     * @param bool             allowIfAllAbstainDecisions         Whether to grant access if all voters abstained or not
     * @param bool             allowIfEqualGrantedDeniedDecisions Whether to grant access if result are equals
     *
     * @throws \InvalidArgumentException
     */
    public function __construct(voters, strategy = self::STRATEGY_AFFIRMATIVE, bool allowIfAllAbstainDecisions = false,
                        bool allowIfEqualGrantedDeniedDecisions = true)
    {
        var strategyMethod;
        if (!voters) {
            throw new \InvalidArgumentException("You must at least add one voter.");
        }

        let strategyMethod = "decide".ucfirst(strategy);
        if (!is_callable([this, strategyMethod])) {
            throw new \InvalidArgumentException(sprintf("The strategy %s is not supported.", strategy));
        }

        let this->voters = voters;
        let this->strategy = strategyMethod;
        let this->allowIfAllAbstainDecisions = allowIfAllAbstainDecisions;
        let this->allowIfEqualGrantedDeniedDecisions = allowIfEqualGrantedDeniedDecisions;
    }

    /**
     * {@inheritdoc}
     */
    public function decide(<TokenInterface> token, array attributes, objectSecure = null)
    {
        var strategy;
        let strategy = this->strategy;
        return this->{strategy}(token, attributes, objectSecure);
    }

    /**
     * {@inheritdoc}
     */
    public function supportsAttribute(attribute) -> boolean
    {
        var voter;
        for voter in this->voters {
            if (voter->supportsAttribute(attribute)) {
                return true;
            }
        }

        return false;
    }

    /**
     * {@inheritdoc}
     */
    public function supportsClass(supportsClass)
    {
        var voter;
        for voter in this->voters {
            if (voter->supportsClass(supportsClass)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Grants access if any voter returns an affirmative response.
     *
     * If all voters abstained from voting, the decision will be based on the
     * allowIfAllAbstainDecisions property value (defaults to false).
     */
    private function decideAffirmative(<TokenInterface> token, array attributes, objectSecure = null)
    {
        var voter, result;
        int deny = 0;
        for voter in this->voters {
            let result = voter->vote(token, objectSecure, attributes);
            switch (result) {
                case VoterInterface::ACCESS_GRANTED:
                    return true;

                case VoterInterface::ACCESS_DENIED:
                    let deny = deny + 1;

                    break;

                default:
                    break;
            }
        }

        if (deny > 0) {
            return false;
        }

        return this->allowIfAllAbstainDecisions;
    }

    /**
     * Grants access if there is consensus of granted against denied responses.
     *
     * Consensus means majority-rule (ignoring abstains) rather than unanimous
     * agreement (ignoring abstains). If you require unanimity, see
     * UnanimousBased.
     *
     * If there were an equal number of grant and deny votes, the decision will
     * be based on the allowIfEqualGrantedDeniedDecisions property value
     * (defaults to true).
     *
     * If all voters abstained from voting, the decision will be based on the
     * allowIfAllAbstainDecisions property value (defaults to false).
     */
    private function decideConsensus(<TokenInterface> token, array attributes, objectSecure = null)
    {
        var voter, result;
        int grant = 0;
        int deny = 0;
        int abstain = 0;
        for voter in this->voters {
            let result = voter->vote(token, objectSecure, attributes);

            switch (result) {
                case VoterInterface::ACCESS_GRANTED:
                    let grant = grant + 1;

                    break;

                case VoterInterface::ACCESS_DENIED:
                    let deny = deny + 1;

                    break;

                default:
                    let abstain = abstain + 1;

                    break;
            }
        }

        if (grant > deny) {
            return true;
        }

        if (deny > grant) {
            return false;
        }

        if (grant == deny && grant != 0) {
            return this->allowIfEqualGrantedDeniedDecisions;
        }

        return this->allowIfAllAbstainDecisions;
    }

    /**
     * Grants access if only grant (or abstain) votes were received.
     *
     * If all voters abstained from voting, the decision will be based on the
     * allowIfAllAbstainDecisions property value (defaults to false).
     */
    private function decideUnanimous(<TokenInterface> token, array attributes, objectSecure = null)
    {
        var attribute, voter, result;
        int grant = 0;
        for attribute in attributes {
            for voter in this->voters {
                let result = voter->vote(token, objectSecure, [attribute]);

                switch (result) {
                    case VoterInterface::ACCESS_GRANTED:
                        let grant = grant + 1;

                        break;

                    case VoterInterface::ACCESS_DENIED:
                        return false;

                    default:
                        break;
                }
            }
        }

        // no deny votes
        if (grant > 0) {
            return true;
        }

        return this->allowIfAllAbstainDecisions;
    }
}
