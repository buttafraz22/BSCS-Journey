using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PD1
{
    public partial class Form1 : Form
    {
        double firstNumber = 0.0d;
        string operation = null;
        int count = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "4";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "5";
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "1";
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if(count == 0)
                firstNumber = 1.0d;
            firstNumber = firstNumber * Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
            operation = "x";
            count++;
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "2";
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "3";
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "6";
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "7";
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "8";
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "9";
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            textBox1.Text = textBox1.Text + "0";
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            firstNumber = firstNumber + Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
            operation = "+";
        }

        private void btnSub_Click(object sender, EventArgs e)
        {
            firstNumber = firstNumber - Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
            operation = "";
        }

        private void btnDiv_Click(object sender, EventArgs e)
        {
            firstNumber = Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
            operation = "/";
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
           // firstNumber = Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
            //operation = "+";
        }
        private void Display(double Result)
        {
            string res = Result.ToString();
            textBox1.Text = res;
        }
        private void btnAns_Click(object sender, EventArgs e)
        {
            double SecondNum = 0.0d;
            SecondNum = Convert.ToDouble(textBox1.Text);
            double Result = 0.0d;
            if(operation == "+")
            {
                Result = firstNumber + SecondNum;
            }
            if(operation == "-")
            {
                Result = firstNumber - SecondNum;
            }
            if (operation == "x")
            {
                Result = firstNumber * SecondNum;
            }
            if (operation == "/")
            {
                if(SecondNum == 0)
                {
                    textBox1.Text = "You can not divide by zero.";
                }
                else  
                    Result = firstNumber / SecondNum;

               
                //Display(Result);
            }
            textBox1.Text = Convert.ToString(Result);
        }
    }
}
