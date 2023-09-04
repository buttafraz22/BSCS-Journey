
namespace Paint
{
    partial class paint
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.pnlColors = new System.Windows.Forms.Panel();
            this.picRed = new System.Windows.Forms.PictureBox();
            this.picGrun = new System.Windows.Forms.PictureBox();
            this.picYul = new System.Windows.Forms.PictureBox();
            this.picBlue = new System.Windows.Forms.PictureBox();
            this.panel1.SuspendLayout();
            this.pnlColors.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picRed)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picGrun)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picYul)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBlue)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.White;
            this.panel1.Controls.Add(this.pnlColors);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(800, 450);
            this.panel1.TabIndex = 0;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.panel1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseMove);
            this.panel1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseUp);
            // 
            // pnlColors
            // 
            this.pnlColors.BackColor = System.Drawing.Color.Gray;
            this.pnlColors.Controls.Add(this.picBlue);
            this.pnlColors.Controls.Add(this.picYul);
            this.pnlColors.Controls.Add(this.picGrun);
            this.pnlColors.Controls.Add(this.picRed);
            this.pnlColors.Location = new System.Drawing.Point(484, 12);
            this.pnlColors.Name = "pnlColors";
            this.pnlColors.Size = new System.Drawing.Size(279, 51);
            this.pnlColors.TabIndex = 0;
            // 
            // picRed
            // 
            this.picRed.BackColor = System.Drawing.Color.Red;
            this.picRed.Location = new System.Drawing.Point(15, 3);
            this.picRed.Name = "picRed";
            this.picRed.Size = new System.Drawing.Size(54, 48);
            this.picRed.TabIndex = 0;
            this.picRed.TabStop = false;
            this.picRed.Click += new System.EventHandler(this.picRed_Click);
            // 
            // picGrun
            // 
            this.picGrun.BackColor = System.Drawing.Color.Lime;
            this.picGrun.Location = new System.Drawing.Point(135, 3);
            this.picGrun.Name = "picGrun";
            this.picGrun.Size = new System.Drawing.Size(54, 48);
            this.picGrun.TabIndex = 1;
            this.picGrun.TabStop = false;
            this.picGrun.Click += new System.EventHandler(this.pictureBox2_Click);
            // 
            // picYul
            // 
            this.picYul.BackColor = System.Drawing.Color.Yellow;
            this.picYul.Location = new System.Drawing.Point(75, 3);
            this.picYul.Name = "picYul";
            this.picYul.Size = new System.Drawing.Size(54, 48);
            this.picYul.TabIndex = 2;
            this.picYul.TabStop = false;
            this.picYul.Click += new System.EventHandler(this.picYul_Click);
            // 
            // picBlue
            // 
            this.picBlue.BackColor = System.Drawing.Color.Blue;
            this.picBlue.Location = new System.Drawing.Point(204, 3);
            this.picBlue.Name = "picBlue";
            this.picBlue.Size = new System.Drawing.Size(54, 48);
            this.picBlue.TabIndex = 3;
            this.picBlue.TabStop = false;
            this.picBlue.Click += new System.EventHandler(this.picBlue_Click);
            // 
            // paint
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.panel1);
            this.Name = "paint";
            this.Text = "Paint";
            this.panel1.ResumeLayout(false);
            this.pnlColors.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picRed)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picGrun)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picYul)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBlue)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel pnlColors;
        private System.Windows.Forms.PictureBox picBlue;
        private System.Windows.Forms.PictureBox picYul;
        private System.Windows.Forms.PictureBox picGrun;
        private System.Windows.Forms.PictureBox picRed;
    }
}

