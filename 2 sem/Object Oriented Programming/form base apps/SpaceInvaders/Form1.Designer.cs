
namespace Pong
{
    partial class frmPong
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmPong));
            this.timeGame = new System.Windows.Forms.Timer(this.components);
            this.lblplayer1 = new System.Windows.Forms.Label();
            this.lblPlayer2 = new System.Windows.Forms.Label();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.progressBar2 = new System.Windows.Forms.ProgressBar();
            this.SuspendLayout();
            // 
            // timeGame
            // 
            this.timeGame.Enabled = true;
            this.timeGame.Interval = 60;
            this.timeGame.Tick += new System.EventHandler(this.timeGame_Tick);
            // 
            // lblplayer1
            // 
            this.lblplayer1.Font = new System.Drawing.Font("Dubai", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblplayer1.ForeColor = System.Drawing.Color.Lime;
            this.lblplayer1.Location = new System.Drawing.Point(12, 9);
            this.lblplayer1.Name = "lblplayer1";
            this.lblplayer1.Size = new System.Drawing.Size(58, 25);
            this.lblplayer1.TabIndex = 3;
            this.lblplayer1.Text = "00";
            this.lblplayer1.Click += new System.EventHandler(this.lblplayer1_Click);
            // 
            // lblPlayer2
            // 
            this.lblPlayer2.Font = new System.Drawing.Font("Dubai", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPlayer2.ForeColor = System.Drawing.Color.Gray;
            this.lblPlayer2.Location = new System.Drawing.Point(821, 9);
            this.lblPlayer2.Name = "lblPlayer2";
            this.lblPlayer2.Size = new System.Drawing.Size(58, 25);
            this.lblPlayer2.TabIndex = 4;
            this.lblPlayer2.Text = "00";
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(42, 9);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(43, 23);
            this.progressBar1.TabIndex = 5;
            this.progressBar1.Value = 100;
            // 
            // progressBar2
            // 
            this.progressBar2.BackColor = System.Drawing.Color.Gray;
            this.progressBar2.Location = new System.Drawing.Point(772, 9);
            this.progressBar2.Name = "progressBar2";
            this.progressBar2.Size = new System.Drawing.Size(43, 23);
            this.progressBar2.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.progressBar2.TabIndex = 6;
            this.progressBar2.Value = 100;
            this.progressBar2.Click += new System.EventHandler(this.progressBar2_Click);
            // 
            // frmPong
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(891, 472);
            this.Controls.Add(this.progressBar2);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.lblPlayer2);
            this.Controls.Add(this.lblplayer1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmPong";
            this.Text = "Pong";
            this.Load += new System.EventHandler(this.frmPong_Load);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Timer timeGame;
        private System.Windows.Forms.Label lblplayer1;
        private System.Windows.Forms.Label lblPlayer2;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.ProgressBar progressBar2;
    }
}

