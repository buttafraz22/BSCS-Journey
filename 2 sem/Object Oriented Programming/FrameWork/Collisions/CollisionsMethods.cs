using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;
using PongFrameWork.Enums;
using PongFrameWork.Movements;

namespace PongFrameWork.Collisions
{
    public class CollisionsMethods:ICollisionAction
    {
        public void performAction(IEventRaise game , GameObject pillOrPlayer ,GameObject ball)
        {
            GameObject underConsideration = null;
            if(pillOrPlayer.OType == ObjectType.pill && ball.OType == ObjectType.ball)
            {
                underConsideration = pillOrPlayer;
            }
            else if(pillOrPlayer.OType == ObjectType.player && ball.OType == ObjectType.ball)
            {
                underConsideration = ball;
            }
            game.RaiseCollisionEvent(underConsideration);
        }
        public static void performAction1(Game game, Fire pillOrPlayer, GameObject g2)
        {
            // GameObject underConsideration = null;
            if (pillOrPlayer.OType == ObjectType.fires && g2.OType == ObjectType.other)
            {
                game.removeFire(pillOrPlayer);
            }
        }
    }
}

