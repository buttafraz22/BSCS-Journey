using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;
using System.Drawing;

namespace PongFrameWork.Movements
{
    public class Horizontal:IMovement
    {
        private int speed;
        private Point bounds;
        private string direction;
        private int checkForOut;
        public Horizontal(int speed, Point bounds, string direction)
        {
            this.speed = speed;
            this.bounds = bounds;
            this.direction = direction;
            checkForOut = 200;
        }
        public Point Move(Point location)
        {
            if(location.X <= 0)
            {
                direction = "right";
            }
            else if(location.X >= bounds.X)
            {
                direction = "left";
            }

            switch(direction){

                case "right":
                    location.X += speed;
                    break;

                case "left":
                    location.X -= speed;
                    break;

                default:
                    location.X = location.X;
                    break;
            }
            return location;
        }
    }
}
