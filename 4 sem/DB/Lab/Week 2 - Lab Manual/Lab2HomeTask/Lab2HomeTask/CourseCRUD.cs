using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2HomeTask
{
    public partial class CourseCRUD : Form
    {
        public CourseCRUD()
        {
            InitializeComponent();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("INSERT INTO Course VALUES (@Name, @Code)", con);
            cmd.Parameters.AddWithValue("@Name", txtName.Text);
            cmd.Parameters.AddWithValue("@Code", txtCode.Text);
            cmd.ExecuteNonQuery();


            SqlCommand cmdShow = new SqlCommand("SELECT Name AS CourseName, Code  FROM Course", con);
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

        private void CourseCRUD_Load(object sender, EventArgs e)
        {
            this.MinimumSize = new System.Drawing.Size(792,489);
        }

        private void CourseCRUD_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("UPDATE Course SET Name = @name WHERE Code = @code", con);
            cmd.Parameters.AddWithValue("@name", txtName.Text);
            cmd.Parameters.AddWithValue("@code", txtCode.Text);
            // SqlDataAdapter da = new SqlDataAdapter(cmd);
            cmd.ExecuteNonQuery();

            SqlCommand cmdShow = new SqlCommand("SELECT Name AS CourseName, Code  FROM Course", con);
            SqlDataAdapter da = new SqlDataAdapter(cmdShow);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void btnRead_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmdShow = new SqlCommand("SELECT Name AS CourseName, Code  FROM Course", con);
            SqlDataAdapter da = new SqlDataAdapter(cmdShow);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("DELETE FROM Course WHERE Code = @id", con);
            cmd.Parameters.AddWithValue("@id", txtCode.Text);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }
    }
}
