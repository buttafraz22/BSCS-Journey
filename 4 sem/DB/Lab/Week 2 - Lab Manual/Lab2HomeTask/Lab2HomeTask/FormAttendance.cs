using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Lab2HomeTask
{
    public partial class FormAttendance : Form
    {
        public FormAttendance()
        {
            InitializeComponent();
        }
        /*
         */
        private void button1_Click(object sender, EventArgs e)
        {
            MarkStudentsAsAbsent();

            Form frm = new Form1();
            this.Hide(); frm.Show();
        }

        private void FormAttendance_Load(object sender, EventArgs e)
        {
            this.MinimumSize = new System.Drawing.Size(638,436);
            // Today's date in the label
            label1.Text = "Today's date = ";
            label1.Text += DateTime.Now.ToString("dd/MM/yyyy");
            
            // Configuring the SQL command to fetch data from enrollments
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("SELECT * FROM Enrollments",con);
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;

            // Modifying the Data Width in the column
            DataGridViewColumn column = dataGridView1.Columns[0];
            column.Width = 100;

            column = dataGridView1.Columns[1];
            column.Width = 180;

            // Adding the Mark as P button on the dataGridView
            DataGridViewButtonColumn AttendanceButton = new DataGridViewButtonColumn();
            AttendanceButton.Name = "Mark as P";
            AttendanceButton.Text = "Mark as P";
            AttendanceButton.UseColumnTextForButtonValue = true;
            int columnIndex = 2;
            if (dataGridView1.Columns["Mark as P"] == null)
            {
                dataGridView1.Columns.Insert(columnIndex, AttendanceButton);
                dataGridView1.CellClick += dataGridView1_CellClick;
            }

            // Adding Mark as A button on the dataGridView
            DataGridViewButtonColumn AbsentButton = new DataGridViewButtonColumn();
            AbsentButton.Name = "Mark as A";
            AbsentButton.Text = "Mark as A";
            AbsentButton.UseColumnTextForButtonValue = true;
            columnIndex = 3;
           
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            
        }
        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            //MessageBox.Show(sender.Text.ToString());
            if (e.ColumnIndex == dataGridView1.Columns["Mark as P"].Index)
            {
                int [] COLUMNS = {0,1};
                string nameStudent = dataGridView1[COLUMNS[0] , e.RowIndex].Value.ToString();
                string nameCourse = dataGridView1[COLUMNS[1] , e.RowIndex].Value.ToString();
                //string currentDate = DateTime.Now.ToString(); no need, we have managed it in the query

                var con = Configuration.getInstance().getConnection();
                SqlCommand cmd = new SqlCommand("INSERT INTO Attendance (StudentRegNo,CourseName,Status) VALUES (@reg,@course,@status)",con);
                cmd.Parameters.AddWithValue("@reg", nameStudent);
                cmd.Parameters.AddWithValue("@course", nameCourse);
                cmd.Parameters.AddWithValue("@status" , 'P');
                cmd.ExecuteNonQuery();

                // this is a placeholder logic, we need it to differentiate in the next half when we are exiting
                // to mark absents
                dataGridView1[COLUMNS[0], e.RowIndex].Value = "-"+nameStudent;
            }
           
        }

        private void FormAttendance_FormClosed(object sender, FormClosedEventArgs e)
        {
            MarkStudentsAsAbsent();
            Application.Exit();
        }

        private void MarkStudentsAsAbsent() {
            try
            {
                foreach (DataGridViewRow row in dataGridView1.Rows)
                {
                    //if (Object.ReferenceEquals(row.Cells[0].Value.ToString(),null)) break;
                    var nameS = row.Cells[0].Value;
                    if (nameS == null) return;
                    nameS = nameS.ToString();
                    string nameSt = (string)nameS;
                    if (nameSt.StartsWith("-")) continue;
                   
                    string nameCourse = row.Cells[1].Value.ToString();

                    // the server side 
                    var con = Configuration.getInstance().getConnection();
                    SqlCommand cmd = new SqlCommand("INSERT INTO Attendance (StudentRegNo,CourseName) VALUES (@reg,@course)", con);
                    cmd.Parameters.AddWithValue("@reg", nameSt);
                    cmd.Parameters.AddWithValue("@course", nameCourse);
                    //cmd.Parameters.AddWithValue("@status", 'P');
                    cmd.ExecuteNonQuery();
                }
            }
            catch(Exception ex)
            {
                return;
            }
        }
    }
}
