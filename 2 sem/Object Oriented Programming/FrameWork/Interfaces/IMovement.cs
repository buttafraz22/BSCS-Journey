using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace PongFrameWork.Interfaces
{
    public interface IMovement
    {
        Point Move(Point location);
    }
}
