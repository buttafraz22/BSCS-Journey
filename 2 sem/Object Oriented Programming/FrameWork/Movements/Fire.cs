using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PongFrameWork.Interfaces;
using System.Windows.Forms;
using System.Drawing;
using PongFrameWork.Enums;

namespace PongFrameWork.Movements
{
    public class Fire 
    {
        private PictureBox Pb;
        private IMovement movement;
        private ObjectType oType;

        public Fire(Image img ,Point location , IMovement movement, ObjectType oType)
        {
            Pb = new PictureBox();
            Pb.Image = img;
            Pb.Size = img.Size;
            Pb.Width = img.Width;
            Pb.Height = img.Height;
            Pb.BackColor = Color.Transparent;
            Pb.Location = location;

            this.movement = movement;
            this.oType = oType;
        }

        public PictureBox Pb1 { get => Pb; set => Pb = value; }
        public IMovement Movement { get => movement; set => movement = value; }
        public ObjectType OType { get => oType; set => oType = value; }

        public void MoveGameObj()
        {
            Pb.Location = movement.Move(Pb.Location) ;
        }
    }
}
