using PongFrameWork.Interfaces;
using System.Drawing;
using System.Windows.Forms;

namespace PongFrameWork.Movements
{
    public class keyMovements : IMovement
    {
        private int speed;
        private Point bounds;

        //private int checkForOut;
        private int moveAction;
        public keyMovements(int speed, Point bounds)
        {
            this.speed = speed;
            this.bounds = bounds;

            //  checkForOut = 100;
        }
        public void keyPress(Keys keyCode)
        {
            if (keyCode == Keys.Up)
            {
                moveAction = 1;
            }
            else if (keyCode == Keys.Down)
            {
                moveAction = 2;
            }
            else if (keyCode == Keys.A)
            {
                moveAction = 3;
            }
            else if (keyCode == Keys.Z)
            {
                moveAction = 4;
            }
        }
        public Point Move(Point location)
        {
            if (moveAction != 0)
            {
                if (moveAction == 1)
                {
                    location.Y -= speed;
                }
                if (moveAction == 3)
                {
                    location.Y -= speed;
                }
                if (moveAction == 2)
                {
                    location.Y += speed;
                }
                if (moveAction == 4)
                {
                    location.Y += speed;
                }
                moveAction = 0;
            }
            return location;

        }
    }
}
