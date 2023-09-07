using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2HomeTask
{
    public partial class Enrollments : Form
    {
        public Enrollments()
        {
            InitializeComponent();
        }

        private void Enrollments_Load(object sender, EventArgs e)
        {
            this.MinimumSize = new System.Drawing.Size(389, 489);
            var con = Configuration.getInstance().getConnection();

            // SQL Query to fill data of student in the table
            SqlCommand cmd= new SqlCommand("SELECT Name FROM Student",con);
            SqlDataAdapter dataAdapter= new SqlDataAdapter(cmd);
            DataTable dataTable= new DataTable();
            dataAdapter.Fill(dataTable);
            dataGridView1.DataSource= dataTable;

            // SQL Query to fill data of Course
            cmd = new SqlCommand("SELECT Name FROM Course",con);
            dataAdapter = new SqlDataAdapter(cmd);
            dataTable = new DataTable();
            dataAdapter.Fill(dataTable);
            dataGridView2.DataSource= dataTable;

            // SQL Query to fill data of registered courses
            cmd = new SqlCommand("SELECT StudentRegNo,CourseName FROM Enrollments", con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView3.DataSource = dt;
        }

        private void Enrollments_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            string course = txtCourse.Text;

            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("INSERT INTO Enrollments VALUES (@StudentRegNo, @CourseName)",con);
            cmd.Parameters.AddWithValue("@StudentRegNo",name);
            cmd.Parameters.AddWithValue("@CourseName", course);
            cmd.ExecuteNonQuery();

            // SQL Query to fill data of courses Registered in the grid
            cmd = new SqlCommand("SELECT * FROM Enrollments", con);
            SqlDataAdapter dataAdapter = new SqlDataAdapter(cmd);
            DataTable dataTable = new DataTable();
            dataAdapter.Fill(dataTable);
            dataGridView3.DataSource = dataTable;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frm = new Form1();
            this.Hide(); frm.Show();
        }

        private void dataGridView3_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (dataGridView3.Rows[e.RowIndex].Cells["Unregister"].ColumnIndex == e.ColumnIndex) {
                string name = dataGridView3.Rows[e.RowIndex].Cells[1].Value.ToString();
                string course = dataGridView3.Rows[e.RowIndex].Cells[2].Value.ToString();
                
                // MessageBox.Show(name + " " + course);

                // SQL Query to unregister from course
                var con = Configuration.getInstance().getConnection();
                SqlCommand cmd = new SqlCommand("DELETE FROM Enrollments WHERE (StudentRegNo = @name) AND (CourseName = @courseName)",con);
                cmd.Parameters.AddWithValue("@name",name);
                cmd.Parameters.AddWithValue("@courseName",course);
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                

                cmd = new SqlCommand("SELECT * FROM Enrollments", con);
                SqlDataAdapter dataAdapter = new SqlDataAdapter(cmd);
                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);
                dataGridView3.DataSource = dataTable;
            }
        }
    }
}
