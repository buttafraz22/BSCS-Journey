using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using PongFrameWork.Interfaces;

namespace PongFrameWork.Movements
{
    public class FireMovement : IMovement
    {
        private Point bounds;
        private int speed;
        private string typeFire;
        private int offset;

        public FireMovement(int speed , Point bounds , string typeFire , int offset)
        {
            this.speed = speed;
            this.bounds = bounds;
            this.typeFire = typeFire;
            this.offset = offset;
        }

        public FireMovement() // default constructor for initializing
        {
            this.speed = 10;
           // this.bounds = bounds;
            this.typeFire = "horizontal";
            this.offset = 20;
        }

        public Point Move(Point location)
        {
            switch (typeFire)
            {
                case "horizontal":
                    if(location.X > 0)
                    {
                        location.X += speed;
                    }
                    break;
                case "vertical":
                    if(location.Y > 0)
                    {
                        location.Y -= speed;
                    }
                    break;
                default:
                    return location ;
            }
            return location;
        }
    }
}
