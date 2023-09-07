using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Lab2HomeTask
{
    public partial class StudentCRUD : Form
    {
        public StudentCRUD()
        {
            InitializeComponent();
        }

        private void txtReg_TextChanged(object sender, EventArgs e)
        {
            if (txtReg.Text.Length < 10 ){
                this.lblRegWarning.Text = "Less Character limit than 10";
            }
            else
            {
                this.lblRegWarning.Text = "";
            }
        }

        private void StudentCRUD_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("INSERT INTO Student values (@Registration_Number, @Name, @Department, @Session, @Address)", con);
            cmd.Parameters.AddWithValue("@Session", int.Parse(txtSession.Text));
            cmd.Parameters.AddWithValue("@Name", txtName.Text);
            cmd.Parameters.AddWithValue("@Department", txtDepartment.Text);
            cmd.Parameters.AddWithValue("@Registration_Number" , txtReg.Text);
            cmd.Parameters.AddWithValue("@Address", txtAddress.Text);
            cmd.ExecuteNonQuery();


            SqlCommand cmdShow = new SqlCommand("SELECT Registration_Number AS Registration, Name FROM Student", con);
            SqlDataAdapter da = new SqlDataAdapter(cmdShow);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frm = new Form1();
            this.Hide(); frm.Show();
        }

        private void FillDataTable() {
            
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmdShow = new SqlCommand("SELECT Registration_Number AS Registration, Name FROM Student", con);
            SqlDataAdapter da = new SqlDataAdapter(cmdShow);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void StudentCRUD_Load(object sender, EventArgs e)
        {
            FillDataTable();
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("UPDATE Student SET Name = @name, Department = @department, Session = @session WHERE Registration_Number = @registration_number", con);
            cmd.Parameters.AddWithValue("@name", txtName.Text);
            cmd.Parameters.AddWithValue("@department", txtDepartment.Text);
            cmd.Parameters.AddWithValue("@session", int.Parse(txtSession.Text));
            cmd.Parameters.AddWithValue("@registration_number", txtReg.Text);
            // SqlDataAdapter da = new SqlDataAdapter(cmd);
            cmd.ExecuteNonQuery();

            SqlCommand cmdShow = new SqlCommand("SELECT Registration_Number AS Registration, Name FROM Student", con);
            SqlDataAdapter da = new SqlDataAdapter(cmdShow);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void btnRead_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("Select * from Student", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("DELETE FROM Student WHERE Registration_Number = @id", con);
            cmd.Parameters.AddWithValue("@id", txtReg.Text);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }
    }
}
