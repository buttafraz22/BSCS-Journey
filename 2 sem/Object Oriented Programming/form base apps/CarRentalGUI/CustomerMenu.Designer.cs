
namespace CarRentalGUI
{
    partial class CustomerMenu
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
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.MessageWelcome = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.bookCarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.updatePersonalRecordsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewPerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.backToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(229, 45);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(308, 34);
            this.label3.TabIndex = 25;
            this.label3.Text = "Car Rental Management";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(313, 113);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(207, 34);
            this.label1.TabIndex = 27;
            this.label1.Text = "Customer Menu";
            // 
            // MessageWelcome
            // 
            this.MessageWelcome.Font = new System.Drawing.Font("Stencil", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MessageWelcome.Location = new System.Drawing.Point(285, 184);
            this.MessageWelcome.Name = "MessageWelcome";
            this.MessageWelcome.Size = new System.Drawing.Size(231, 83);
            this.MessageWelcome.TabIndex = 28;
            this.MessageWelcome.Text = "Welcome! Select any Option to continue.";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Dock = System.Windows.Forms.DockStyle.Left;
            this.menuStrip1.Font = new System.Drawing.Font("Forte", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bookCarToolStripMenuItem,
            this.updatePersonalRecordsToolStripMenuItem,
            this.viewPerToolStripMenuItem,
            this.backToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(187, 450);
            this.menuStrip1.TabIndex = 29;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // bookCarToolStripMenuItem
            // 
            this.bookCarToolStripMenuItem.Name = "bookCarToolStripMenuItem";
            this.bookCarToolStripMenuItem.Size = new System.Drawing.Size(143, 19);
            this.bookCarToolStripMenuItem.Text = "Book Car";
            this.bookCarToolStripMenuItem.TextDirection = System.Windows.Forms.ToolStripTextDirection.Horizontal;
            this.bookCarToolStripMenuItem.Click += new System.EventHandler(this.bookCarToolStripMenuItem_Click);
            // 
            // updatePersonalRecordsToolStripMenuItem
            // 
            this.updatePersonalRecordsToolStripMenuItem.Name = "updatePersonalRecordsToolStripMenuItem";
            this.updatePersonalRecordsToolStripMenuItem.Size = new System.Drawing.Size(143, 19);
            this.updatePersonalRecordsToolStripMenuItem.Text = "Update Personal Records";
            this.updatePersonalRecordsToolStripMenuItem.TextDirection = System.Windows.Forms.ToolStripTextDirection.Horizontal;
            this.updatePersonalRecordsToolStripMenuItem.Click += new System.EventHandler(this.updatePersonalRecordsToolStripMenuItem_Click);
            // 
            // viewPerToolStripMenuItem
            // 
            this.viewPerToolStripMenuItem.Name = "viewPerToolStripMenuItem";
            this.viewPerToolStripMenuItem.Size = new System.Drawing.Size(143, 19);
            this.viewPerToolStripMenuItem.Text = "View personal Records";
            this.viewPerToolStripMenuItem.Click += new System.EventHandler(this.viewPerToolStripMenuItem_Click);
            // 
            // backToolStripMenuItem
            // 
            this.backToolStripMenuItem.Name = "backToolStripMenuItem";
            this.backToolStripMenuItem.Size = new System.Drawing.Size(143, 19);
            this.backToolStripMenuItem.Text = "Back";
            this.backToolStripMenuItem.Click += new System.EventHandler(this.backToolStripMenuItem_Click);
            // 
            // CustomerMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Info;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.MessageWelcome);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.Name = "CustomerMenu";
            this.Text = "CustomerMenu";
            this.Load += new System.EventHandler(this.CustomerMenu_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label MessageWelcome;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem bookCarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem updatePersonalRecordsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewPerToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem backToolStripMenuItem;
    }
}