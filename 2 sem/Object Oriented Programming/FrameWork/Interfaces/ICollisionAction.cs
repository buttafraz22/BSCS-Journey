using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PongFrameWork.Interfaces
{
   public interface ICollisionAction
    {
         void performAction(IEventRaise game , GameObject g1, GameObject g2);
    }
}
