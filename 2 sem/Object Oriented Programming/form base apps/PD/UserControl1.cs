using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PD
{
    public partial class UserControl1: UserControl
    {
        private EventHandler onChoice;
        private string dataType;
        public UserControl1()
        {
            InitializeComponent();
        }

        private void UserControl1_Load(object sender, EventArgs e)
        {

        }

        private void cmbChoice_SelectedIndexChanged(object sender, EventArgs e)
        {
            dataType = cmbChoice.Text;
            txtChoice.Text = dataType;
            onChoice?.Invoke(this, EventArgs.Empty);
        }
    }
}
