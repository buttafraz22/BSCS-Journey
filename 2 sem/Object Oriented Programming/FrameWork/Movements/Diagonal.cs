using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;
using System.Drawing;

namespace PongFrameWork.Movements
{
    public class Diagonal : IMovement
    {
        private int speed;
        private Point bounds;
        private string direction;
        private int height;
        private int width;
        private int offset;
       // private string prevDirection = null;

        public int Height { get => height; set => height = value; }
        public int Width { get => width; set => width = value; }

        public Diagonal(int speed, Point bounds, int height, int width,int offset, string direction)
        {
            this.speed = speed;
            this.bounds = bounds;
            this.direction = direction;
            this.height = height;
            this.width = width;
            this.offset = offset;
        }
        internal void assignDirection(Point location)
        { 
            if(location.X <= 0)
            {
                direction = "downRight";
            }
            else if(location.Y + offset >= bounds.Y)
            {
                direction = "upRight";
               // move = 1;
            }
            else if(location.X + offset >= bounds.X)
            {
                direction = "upLeft";
               // move = 2;
            }
            else if(location.Y <= 0)
            {
                direction = "downLeft";
            }
        }

        public void Direction()
        {
            //if(move == 1)
            //{
            //    direction = "downRight";
            //}
            //else if(move == 2)
            //{
            //    direction = "upLeft";
            //}
        }
        public Point Move(Point location)
        {
            assignDirection(location);

            if (direction == "downRight")
            {
                location.X += speed;
                location.Y += speed;
            }
            if (direction == "downLeft")
            {
                location.X -= speed;
                location.Y += speed;
            }
            if (direction == "upLeft")
            {
                location.Y -= speed;
                location.X -= speed;
            }
            if (direction == "upRight")
            {
                location.Y -= speed;
                location.X += speed;
            }
            //Direction();
            //move = 0;
            return location;
        }
    }
}
