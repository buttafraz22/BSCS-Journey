using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using PongFrameWork.Interfaces;
using PongFrameWork.Enums;

namespace PongFrameWork
{
    public class GameObject
    {
        private PictureBox Pb;
        private IMovement movement;
        private ObjectType oType;
        public GameObject(Image img,int left,int top , IMovement movement, ObjectType otype)
        {
            Pb = new PictureBox();
            Pb.Image = img;
            Pb.Width = img.Width;
            Pb.Height = img.Height;
            Pb.Left = left;
            Pb.Top = top;
            Pb.Size = img.Size;

            Pb.BackColor = Color.Transparent;
            this.oType = otype;
            this.movement = movement;
        }
        public PictureBox Pb1 { get => Pb; set => Pb = value; }
        public IMovement Movement { get => movement; set => movement = value; }
        public ObjectType OType { get => oType; set => oType = value; }

        public void MoveGameObj()
        {
            Pb.Location = movement.Move(Pb.Location);
        }
        
    }
}
