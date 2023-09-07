using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace SQLlab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("Insert into Table_1 values (@ID, @Name, @Department)", con);
            cmd.Parameters.AddWithValue("@ID", int.Parse(txtID.Text));
            cmd.Parameters.AddWithValue("@Name", txtName.Text);
            cmd.Parameters.AddWithValue("@Department", txtDepartment.Text);
            cmd.ExecuteNonQuery();
            MessageBox.Show("Successfully saved");

        }

        private void btnRead_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("Select * from Table_1", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            setDataTable(da);
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("UPDATE Table_1 SET Name = @name, Department = @dep WHERE ID = @id", con);
            cmd.Parameters.AddWithValue("@id", int.Parse(txtID.Text));
            cmd.Parameters.AddWithValue("@name", txtName.Text);
            cmd.Parameters.AddWithValue("@dep", txtDepartment.Text);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            setDataTable(da);
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("DELETE FROM Table_1 WHERE ID = @id",con);
            cmd.Parameters.AddWithValue("@id" , int.Parse(txtID.Text));
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            setDataTable(da);
        }

        private void setDataTable(SqlDataAdapter da) {
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
        }
    }
}
