using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using PdfSharp;
using PdfSharp.Drawing;
using PdfSharp.Pdf;
using static System.Windows.Forms.AxHost;

namespace Lab2HomeTask
{
    public partial class FormAttendaceUpdate : Form
    {
        string textCourseSelected;
        public FormAttendaceUpdate()
        {
            InitializeComponent();
        }

        private void FormAttendaceUpdate_Load(object sender, EventArgs e)
        {
            this.MinimumSize = new Size(816, 432);
            FillCourseRecord();
        }

        private void FillCourseRecord() { 
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("SELECT Name FROM Course",con);
            SqlDataReader sqlReader = cmd.ExecuteReader();

            while (sqlReader.Read())
            {
                comboBox1.Items.Add(sqlReader["Name"].ToString());
            }

            sqlReader.Close();
        }

        private void btnFetch_Click(object sender, EventArgs e)
        {
            textCourseSelected = "";
            textCourseSelected = comboBox1.Text;
            dataGridView1.Columns.Clear();
            dataGridView1.AllowUserToAddRows = true;

            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("SELECT StudentRegNo FROM Enrollments WHERE CourseName = @course",con);
            cmd.Parameters.AddWithValue("@course",textCourseSelected);
            SqlDataAdapter dataAdapter= new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            dataAdapter.Fill(dt);
            dataGridView1.DataSource = dt;
            dataGridView1.AllowUserToAddRows = false;

            // Adding a Checkbox for Presence Status
            DataGridViewCheckBoxColumn checkColumn = new DataGridViewCheckBoxColumn();
            checkColumn.Name = "Present";
            checkColumn.HeaderText = "Present";
            checkColumn.Width = 50;
            checkColumn.ReadOnly = false;
            checkColumn.FillWeight = 10; //if the datagridview is resized (on form resize) the checkbox won't take up too much; value is relative to the other columns' fill values
            dataGridView1.Columns.Add(checkColumn);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MarkStudents();
            Form frm = new Form1();
            this.Hide(); frm.Show();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == dataGridView1.Columns["Present"].Index) {
                // logic shifted to mark students function
            }
        }

        private void FormAttendaceUpdate_FormClosed(object sender, FormClosedEventArgs e)
        {
            MarkStudents();
            Application.Exit();
        }

        private void MarkStudents() {
            foreach(DataGridViewRow row in dataGridView1.Rows) {
                var nameS = row.Cells[0].Value;
                if (nameS == null) return;

                DataGridViewCheckBoxCell chkchecking = row.Cells[1] as DataGridViewCheckBoxCell;
               // if (chkchecking.Value == null) return;
                
                //We need to mark absent students first. This is done by checking whether the checkbox is null || not.
                if (chkchecking.Value == null) {
                    string studentName = dataGridView1[0, row.Index].Value.ToString();
                    //MessageBox.Show(studentName);
                    var con = Configuration.getInstance().getConnection();
                    SqlCommand cmd = new SqlCommand("INSERT INTO Attendance (StudentRegNo,CourseName) VALUES (@reg,@course)", con);
                    cmd.Parameters.AddWithValue("@reg", studentName);
                    cmd.Parameters.AddWithValue("@course", textCourseSelected);
                    //cmd.Parameters.AddWithValue("@status", 'A');
                    cmd.ExecuteNonQuery();
                }

                // marking present students
                else if ((bool)chkchecking.Value == true) {
                    string studentName = dataGridView1[0, row.Index].Value.ToString();
                    var con = Configuration.getInstance().getConnection();
                    SqlCommand cmd = new SqlCommand("INSERT INTO Attendance (StudentRegNo,CourseName,Status) VALUES (@reg,@course,@status)", con);
                    cmd.Parameters.AddWithValue("@reg", studentName);
                    cmd.Parameters.AddWithValue("@course", textCourseSelected);
                    cmd.Parameters.AddWithValue("@status", 'P');
                    cmd.ExecuteNonQuery();
                }

            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            textCourseSelected = "";
            textCourseSelected = comboBox1.Text;

            // generating SQL query to fetch data 
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("SELECT * FROM Attendance WHERE CourseName = @course", con);
            cmd.Parameters.AddWithValue("@course",textCourseSelected);
            SqlDataAdapter dataAdapter = new SqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            dataAdapter.Fill(ds);

            //generating pdf instance
            PdfDocument pdf = new PdfDocument();
            pdf.Info.Title = textCourseSelected + "Attendance Record";
            PdfPage pdfPage = pdf.AddPage();
            XGraphics graph = XGraphics.FromPdfPage(pdfPage);
            XFont font = new XFont("Times New Roman", 12, XFontStyle.Regular);

            string name = "", date = "", attendance = "";
            int yPoint = 100;
            foreach(DataRow row in ds.Tables[0].Rows)
            {
                name = row["StudentRegNo"].ToString();
                date = row["timeattend"].ToString();
                attendance = row["Status"].ToString();
                graph.DrawString(name, font, XBrushes.Black, new XRect(40, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);

                graph.DrawString(date, font, XBrushes.Black, new XRect(280, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);

                graph.DrawString(attendance, font, XBrushes.Black, new XRect(420, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);

                yPoint = yPoint + 40;
            }
            string fileName = string.Empty;
            using (SaveFileDialog fdb = new SaveFileDialog())
            {
                fdb.Filter = "pdf files (*.pdf)|*.pdf|All files(*.*) | *.* ";
                fdb.DefaultExt = "pdf";      // the default pdf extension
                if (fdb.ShowDialog() == DialogResult.OK)
                {
                    fileName = fdb.FileName;        
                }
            }
            pdf.Save(fileName);
            MessageBox.Show("Completed report generation. The Attendance report for " + textCourseSelected
                             + " is available at "+fileName);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textCourseSelected = "";
            textCourseSelected = comboBox1.Text;

            // generating SQL query to fetch data 
            var con = Configuration.getInstance().getConnection();
            SqlCommand cmd = new SqlCommand("SELECT * FROM Attendance", con);
            cmd.Parameters.AddWithValue("@course", textCourseSelected);
            SqlDataAdapter dataAdapter = new SqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            dataAdapter.Fill(ds);

            //generating pdf instance
            PdfDocument pdf = new PdfDocument();
            pdf.Info.Title = "Complete Attendance Record";
            PdfPage pdfPage = pdf.AddPage();
            XGraphics graph = XGraphics.FromPdfPage(pdfPage);
            XFont font = new XFont("Times New Roman", 8, XFontStyle.Regular);

            string name = "", date = "", attendance = "",course = "";
            int yPoint = 100;
            foreach (DataRow row in ds.Tables[0].Rows)
            {
                name = row["StudentRegNo"].ToString();
                date = row["timeattend"].ToString();
                attendance = row["Status"].ToString();
                course = row["CourseName"].ToString();
                
                // drawing the rectangle on the pdf page
                graph.DrawString(name, font, XBrushes.Black, new XRect(40, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);

                graph.DrawString(course, font, XBrushes.Black, new XRect(120, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);

                graph.DrawString(date, font, XBrushes.Black, new XRect(280, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);

                graph.DrawString(attendance, font, XBrushes.Black, new XRect(420, yPoint, pdfPage.Width.Point, pdfPage.Height.Point), XStringFormats.TopLeft);

                yPoint = yPoint + 40;
            }
            string fileName = "Complete Attendance Record.pdf";
            pdf.Save(fileName);
            MessageBox.Show("Completed report generation.");
        }
    }
}
