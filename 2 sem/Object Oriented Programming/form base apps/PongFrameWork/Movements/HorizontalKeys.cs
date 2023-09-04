using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;
using System.Drawing;
using System.Windows.Forms;

namespace PongFrameWork.Movements
{
    public class HorizontalKeys:IMovement
    {
        private int speed;
        private Point bounds;

        //private int checkForOut;
        private int moveAction;
        public HorizontalKeys(int speed, Point bounds)
        {
            this.speed = speed;
            this.bounds = bounds;

            //  checkForOut = 100;
        }
        public void keyPress(Keys keyCode)
        {
            if (keyCode == Keys.Left)
            {
                moveAction = 1;
            }
            else if (keyCode == Keys.Right)
            {
                moveAction = 2;
            }
        }
        public Point Move(Point location)
        {
            if (moveAction != 0)
            {
                if (moveAction == 1)
                {
                    location.X -= speed;
                }
                if (moveAction == 2)
                {
                    location.X += speed;
                }
                moveAction = 0;
            }
            return location;

        }
    }
}
