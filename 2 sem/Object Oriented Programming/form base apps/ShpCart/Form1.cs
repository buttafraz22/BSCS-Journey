using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ShpCart
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            double ans = Convert.ToDouble(textBox1.Text) * Convert.ToDouble(textBox2.Text);
            textBox3.Text = Convert.ToString(ans);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox4.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            double ans = Convert.ToDouble(textBox1.Text) * Convert.ToDouble(textBox2.Text);
            textBox3.Text = Convert.ToString(ans);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            double ans = Convert.ToDouble(textBox3.Text) + Convert.ToDouble(textBox6.Text);
            textBox7.Text = Convert.ToString(ans);
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            double ans = Convert.ToDouble(textBox4.Text) * Convert.ToDouble(textBox5.Text);
            textBox6.Text = Convert.ToString(ans);
        }
    }
}
