using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Paint
{
    public partial class paint : Form
    {
        Graphics g;
        int x = -1;
        int y = -1;
        bool moving = false;
        Pen pens;
        public paint()
        {
            InitializeComponent();
            g = panel1.CreateGraphics();
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            pens = new Pen(Color.Black, 5);
            pens.StartCap = pens.EndCap = System.Drawing.Drawing2D.LineCap.Round;

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            PictureBox p = (PictureBox)sender; // type casting
            pens.Color = p.BackColor;
        }

        private void picRed_Click(object sender, EventArgs e)
        {
            PictureBox p = (PictureBox)sender; // type casting
            pens.Color = p.BackColor;
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            moving = true;
            x = e.X; //mouse current position co-ordinates generated from events
            y = e.Y;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if(moving && x != -1 && y != -1)
            {
                g.DrawLine(pens, new Point(x, y), e.Location);
                x = e.X;
                y = e.Y;
            }
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            moving = false;
            x = -1;
            y = -1;
        }

        private void picYul_Click(object sender, EventArgs e)
        {
            PictureBox p = (PictureBox)sender; // type casting
            pens.Color = p.BackColor;
        }

        private void picBlue_Click(object sender, EventArgs e)
        {
            PictureBox p = (PictureBox)sender; // type casting
            pens.Color = p.BackColor;
        }
    }
}
