
namespace CarRentalGUI.Forms
{
    partial class FrmEndBooking
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
            this.label2 = new System.Windows.Forms.Label();
            this.txtBookCode = new System.Windows.Forms.TextBox();
            this.lblBill = new System.Windows.Forms.Label();
            this.txtPrice = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtBill = new System.Windows.Forms.TextBox();
            this.btnEndBooking = new System.Windows.Forms.Button();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(212, 28);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(308, 34);
            this.label3.TabIndex = 25;
            this.label3.Text = "Car Rental Management";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(286, 85);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(187, 34);
            this.label1.TabIndex = 27;
            this.label1.Text = "End Bookings";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.Font = new System.Drawing.Font("Dubai", 12F);
            this.label2.Location = new System.Drawing.Point(215, 176);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(131, 23);
            this.label2.TabIndex = 28;
            this.label2.Text = "Booking Code";
            // 
            // txtBookCode
            // 
            this.txtBookCode.Location = new System.Drawing.Point(373, 176);
            this.txtBookCode.Name = "txtBookCode";
            this.txtBookCode.Size = new System.Drawing.Size(155, 20);
            this.txtBookCode.TabIndex = 29;
            this.txtBookCode.TextChanged += new System.EventHandler(this.txtBookCode_TextChanged);
            // 
            // lblBill
            // 
            this.lblBill.Font = new System.Drawing.Font("Dubai", 12F);
            this.lblBill.Location = new System.Drawing.Point(215, 218);
            this.lblBill.Name = "lblBill";
            this.lblBill.Size = new System.Drawing.Size(131, 23);
            this.lblBill.TabIndex = 30;
            this.lblBill.Text = "price";
            this.lblBill.Visible = false;
            // 
            // txtPrice
            // 
            this.txtPrice.Location = new System.Drawing.Point(373, 218);
            this.txtPrice.Name = "txtPrice";
            this.txtPrice.Size = new System.Drawing.Size(155, 20);
            this.txtPrice.TabIndex = 31;
            this.txtPrice.Visible = false;
            this.txtPrice.TextChanged += new System.EventHandler(this.txtPrice_TextChanged);
            // 
            // label4
            // 
            this.label4.Font = new System.Drawing.Font("Dubai", 12F);
            this.label4.Location = new System.Drawing.Point(215, 266);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(131, 23);
            this.label4.TabIndex = 32;
            this.label4.Text = "Bill";
            this.label4.Visible = false;
            // 
            // txtBill
            // 
            this.txtBill.Location = new System.Drawing.Point(373, 270);
            this.txtBill.Name = "txtBill";
            this.txtBill.Size = new System.Drawing.Size(155, 20);
            this.txtBill.TabIndex = 33;
            this.txtBill.Visible = false;
            // 
            // btnEndBooking
            // 
            this.btnEndBooking.Location = new System.Drawing.Point(373, 347);
            this.btnEndBooking.Name = "btnEndBooking";
            this.btnEndBooking.Size = new System.Drawing.Size(75, 23);
            this.btnEndBooking.TabIndex = 34;
            this.btnEndBooking.Text = "End";
            this.btnEndBooking.UseVisualStyleBackColor = true;
            this.btnEndBooking.Visible = false;
            this.btnEndBooking.Click += new System.EventHandler(this.btnEndBooking_Click);
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(731, 113);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(32, 13);
            this.linkLabel1.TabIndex = 35;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Back";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // FrmEndBooking
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Info;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.btnEndBooking);
            this.Controls.Add(this.txtBill);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtPrice);
            this.Controls.Add(this.lblBill);
            this.Controls.Add(this.txtBookCode);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label3);
            this.MaximizeBox = false;
            this.Name = "FrmEndBooking";
            this.Text = "FrmEndBooking";
            this.Load += new System.EventHandler(this.FrmEndBooking_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtBookCode;
        private System.Windows.Forms.Label lblBill;
        private System.Windows.Forms.TextBox txtPrice;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtBill;
        private System.Windows.Forms.Button btnEndBooking;
        private System.Windows.Forms.LinkLabel linkLabel1;
    }
}