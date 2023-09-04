using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using PongFrameWork.Interfaces;

namespace PongFrameWork.Movements
{
    public class ComputerVertical : IMovement
    {
        private int speed;
        private Point bounds;
        private string direction;
        private int checkForOut;
        public ComputerVertical(int speed ,Point bounds , string direction)
        {
            this.speed = speed;
            this.bounds = bounds;
            this.direction = direction;
            checkForOut = 200;
        }
        public Point Move(Point location)
        {
            if(location.Y <= 0)
            {
                direction = "down";
            }
            if(location.Y >= bounds.Y - checkForOut)
            {
                direction = "up";
            }
            if(direction == "up")
            {
                location.Y -= speed;
            }
            if(direction == "down")
            {
                location.Y += speed;
            }
            return location;
        }
    }
}
