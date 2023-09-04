using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Pong;

namespace SpaceInvaders
{
    public partial class FormGameStart : Form
    {
        public FormGameStart()
        {
            InitializeComponent();
        }

        private void FormGameStart_Load(object sender, EventArgs e)
        {
            this.BackgroundImage = SpaceInvaders.Properties.Resources.download__1_;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frm = new frmPong("1v1");
            frm.Show();
            this.Hide();
            this.DialogResult = DialogResult.Yes;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form frm = new frmPong("COMPUTER");
            frm.Show();
            this.Hide();
            this.DialogResult = DialogResult.OK;
        }
    }
}
