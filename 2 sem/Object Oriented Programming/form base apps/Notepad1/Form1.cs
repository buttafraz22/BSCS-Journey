using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Notepad1
{
    public partial class Form1 : Form
    {
        //dialogs
        private OpenFileDialog openFileDialog;
        private SaveFileDialog saveFileDialog;
        private FontDialog fontDialog;
        public Form1()
        {
            InitializeComponent();
        }

        private void menuWord_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            txtEnter.SelectionFont = new Font("Consolas", 12);
            fontDialog = new FontDialog();
        }
        private void newFile() // creates new file
        {
            try
            {
                if (!string.IsNullOrEmpty(this.txtEnter.Text))
                {
                    MessageBox.Show("You need to save first.");
                }
                else
                {
                    this.txtEnter.Text = string.Empty;
                    this.Text = "Untitled";
                }
            }
            catch(Exception ex)
            {

            }
            finally
            {

            }
        }
        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            newFile();
        }
        private void saveFile()
        {
            try
            {
                if (!string.IsNullOrEmpty(this.txtEnter.Text))
                {
                    saveFileDialog = new SaveFileDialog();
                    saveFileDialog.Filter = "Text File (*.txt) | *.txt ";
                    if (saveFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        File.WriteAllText(saveFileDialog.FileName, this.txtEnter.Text);
                        this.Text = saveFileDialog.FileName;
                    }
                }
                else
                {
                    MessageBox.Show("No text in the word editor.");
                }
            }
            catch(Exception ex)
            {

            }
            finally
            {

            }
        }
        private void openFile()
        {
            try // open file
            {
                openFileDialog = new OpenFileDialog();
                
                if(openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    this.txtEnter.Text = File.ReadAllText(openFileDialog.FileName);
                    this.Text = openFileDialog.FileName;
                }
            }
            catch(Exception ex) // exception handling
            {
                MessageBox.Show("Error on trying to open file.");
            }
            finally
            {
                openFileDialog = null;
            }
        }
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFile();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFile();
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveAs();
        }
        private void saveAs()
        {
            try
            {
                if (!string.IsNullOrEmpty(this.txtEnter.Text))
                {
                    saveFileDialog = new SaveFileDialog();
                    saveFileDialog.Filter = "Text File (*.txt) | *.txt ! All Files (*.*) | *.*";
                    if (saveFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        File.WriteAllText(saveFileDialog.FileName, this.txtEnter.Text);
                        this.Text = saveFileDialog.FileName;
                    }
                }
                else
                {
                    MessageBox.Show("No text in the word editor.");
                }
            }
            catch (Exception ex)
            {

            }
            finally
            {

            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (!string.IsNullOrEmpty(this.txtEnter.Text))
                {
                    saveFile();
                }
                else
                {
                    MessageBox.Show("No text in the word editor.");
                }
            }
            catch (Exception ex)
            {

            }
        }

        private void fontToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
               
                if(fontDialog.ShowDialog() == DialogResult.OK)
                {
                    this.txtEnter.Font = fontDialog.Font;
                }
            }
            catch(Exception ex)
            {

            }
            finally
            {

            }
        }

        private void txtEnter_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
