using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PongFrameWork.Interfaces
{
    public interface IEventRaise
    {
        void RaiseCollisionEvent(GameObject Pb);
    }
}
