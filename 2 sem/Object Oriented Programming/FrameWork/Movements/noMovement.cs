using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;
using System.Drawing;

namespace PongFrameWork.Movements
{
    public class noMovement:IMovement
    {
        public Point Move(Point location)
        {
            return location;
        }
    }
}
