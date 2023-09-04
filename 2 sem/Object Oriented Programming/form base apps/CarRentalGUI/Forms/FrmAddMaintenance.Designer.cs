
namespace CarRentalGUI.Forms
{
    partial class FrmAddMaintenance
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
            this.lblLP = new System.Windows.Forms.Label();
            this.txtLP = new System.Windows.Forms.TextBox();
            this.lblOC = new System.Windows.Forms.Label();
            this.txtOilChange = new System.Windows.Forms.TextBox();
            this.txtComments = new System.Windows.Forms.TextBox();
            this.lblComments = new System.Windows.Forms.Label();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(224, 28);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(308, 34);
            this.label3.TabIndex = 26;
            this.label3.Text = "Car Rental Management";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(277, 100);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(211, 34);
            this.label1.TabIndex = 28;
            this.label1.Text = "AddMaintenance";
            // 
            // lblLP
            // 
            this.lblLP.Font = new System.Drawing.Font("Dubai", 9.749999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblLP.Location = new System.Drawing.Point(175, 187);
            this.lblLP.Name = "lblLP";
            this.lblLP.Size = new System.Drawing.Size(129, 28);
            this.lblLP.TabIndex = 29;
            this.lblLP.Text = "Enter License Plate";
            // 
            // txtLP
            // 
            this.txtLP.Location = new System.Drawing.Point(318, 187);
            this.txtLP.Name = "txtLP";
            this.txtLP.Size = new System.Drawing.Size(170, 20);
            this.txtLP.TabIndex = 32;
            this.txtLP.TextChanged += new System.EventHandler(this.txtLP_TextChanged);
            // 
            // lblOC
            // 
            this.lblOC.Font = new System.Drawing.Font("Dubai", 9.749999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOC.Location = new System.Drawing.Point(175, 247);
            this.lblOC.Name = "lblOC";
            this.lblOC.Size = new System.Drawing.Size(129, 28);
            this.lblOC.TabIndex = 33;
            this.lblOC.Text = "Enter Oil Change";
            this.lblOC.Visible = false;
            // 
            // txtOilChange
            // 
            this.txtOilChange.Location = new System.Drawing.Point(318, 248);
            this.txtOilChange.Name = "txtOilChange";
            this.txtOilChange.Size = new System.Drawing.Size(170, 20);
            this.txtOilChange.TabIndex = 34;
            this.txtOilChange.Visible = false;
            // 
            // txtComments
            // 
            this.txtComments.Location = new System.Drawing.Point(318, 299);
            this.txtComments.Name = "txtComments";
            this.txtComments.Size = new System.Drawing.Size(170, 20);
            this.txtComments.TabIndex = 35;
            this.txtComments.Visible = false;
            // 
            // lblComments
            // 
            this.lblComments.Font = new System.Drawing.Font("Dubai", 9.749999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblComments.Location = new System.Drawing.Point(175, 299);
            this.lblComments.Name = "lblComments";
            this.lblComments.Size = new System.Drawing.Size(129, 28);
            this.lblComments.TabIndex = 36;
            this.lblComments.Text = "Enter Comments";
            this.lblComments.Visible = false;
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(678, 355);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(32, 13);
            this.linkLabel1.TabIndex = 38;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Back";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(354, 372);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 39;
            this.button1.Text = "Create";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // FrmAddMaintenance
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Info;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.lblComments);
            this.Controls.Add(this.txtComments);
            this.Controls.Add(this.txtOilChange);
            this.Controls.Add(this.lblOC);
            this.Controls.Add(this.txtLP);
            this.Controls.Add(this.lblLP);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label3);
            this.MaximizeBox = false;
            this.Name = "FrmAddMaintenance";
            this.Text = "FrmAddMaintenance";
            this.Load += new System.EventHandler(this.FrmAddMaintenance_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.FrmAddMaintenance_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblLP;
        private System.Windows.Forms.TextBox txtLP;
        private System.Windows.Forms.Label lblOC;
        private System.Windows.Forms.TextBox txtOilChange;
        private System.Windows.Forms.TextBox txtComments;
        private System.Windows.Forms.Label lblComments;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.Button button1;
    }
}