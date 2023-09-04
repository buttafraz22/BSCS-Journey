
namespace CarRentalGUI.Forms
{
    partial class FrmStartBooking
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
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.txtCustName = new System.Windows.Forms.TextBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.txtCustID = new System.Windows.Forms.TextBox();
            this.txtCustAddress = new System.Windows.Forms.TextBox();
            this.txtCarDetails = new System.Windows.Forms.TextBox();
            this.cmbCategories = new System.Windows.Forms.ComboBox();
            this.btnCheck = new System.Windows.Forms.Button();
            this.btnBook = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.lblCarPlate = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(243, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(308, 34);
            this.label3.TabIndex = 26;
            this.label3.Text = "Car Rental Management";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(294, 60);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(190, 34);
            this.label1.TabIndex = 28;
            this.label1.Text = "Start Booking";
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(699, 30);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(32, 13);
            this.linkLabel1.TabIndex = 38;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Back";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // txtCustName
            // 
            this.txtCustName.Location = new System.Drawing.Point(353, 150);
            this.txtCustName.Name = "txtCustName";
            this.txtCustName.Size = new System.Drawing.Size(131, 20);
            this.txtCustName.TabIndex = 39;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // txtCustID
            // 
            this.txtCustID.Location = new System.Drawing.Point(353, 198);
            this.txtCustID.Name = "txtCustID";
            this.txtCustID.Size = new System.Drawing.Size(131, 20);
            this.txtCustID.TabIndex = 41;
            // 
            // txtCustAddress
            // 
            this.txtCustAddress.Location = new System.Drawing.Point(353, 250);
            this.txtCustAddress.Name = "txtCustAddress";
            this.txtCustAddress.Size = new System.Drawing.Size(131, 20);
            this.txtCustAddress.TabIndex = 42;
            // 
            // txtCarDetails
            // 
            this.txtCarDetails.Location = new System.Drawing.Point(353, 326);
            this.txtCarDetails.Name = "txtCarDetails";
            this.txtCarDetails.Size = new System.Drawing.Size(131, 20);
            this.txtCarDetails.TabIndex = 43;
            this.txtCarDetails.Visible = false;
            // 
            // cmbCategories
            // 
            this.cmbCategories.FormattingEnabled = true;
            this.cmbCategories.Items.AddRange(new object[] {
            "ECONOMY",
            "LUXURY",
            "SEDAN",
            "SUV",
            "BUS"});
            this.cmbCategories.Location = new System.Drawing.Point(353, 286);
            this.cmbCategories.Name = "cmbCategories";
            this.cmbCategories.Size = new System.Drawing.Size(121, 21);
            this.cmbCategories.TabIndex = 44;
            // 
            // btnCheck
            // 
            this.btnCheck.Location = new System.Drawing.Point(639, 213);
            this.btnCheck.Name = "btnCheck";
            this.btnCheck.Size = new System.Drawing.Size(75, 23);
            this.btnCheck.TabIndex = 45;
            this.btnCheck.Text = "Check";
            this.btnCheck.UseVisualStyleBackColor = true;
            this.btnCheck.Click += new System.EventHandler(this.btnCheck_Click);
            // 
            // btnBook
            // 
            this.btnBook.Location = new System.Drawing.Point(639, 284);
            this.btnBook.Name = "btnBook";
            this.btnBook.Size = new System.Drawing.Size(75, 23);
            this.btnBook.TabIndex = 46;
            this.btnBook.Text = "Book";
            this.btnBook.UseVisualStyleBackColor = true;
            this.btnBook.Visible = false;
            this.btnBook.Click += new System.EventHandler(this.btnBook_Click);
            // 
            // label2
            // 
            this.label2.Font = new System.Drawing.Font("Dubai", 12F);
            this.label2.Location = new System.Drawing.Point(244, 146);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(100, 23);
            this.label2.TabIndex = 47;
            this.label2.Text = "Name";
            // 
            // label4
            // 
            this.label4.Font = new System.Drawing.Font("Dubai", 12F);
            this.label4.Location = new System.Drawing.Point(244, 195);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(100, 23);
            this.label4.TabIndex = 48;
            this.label4.Text = "ID";
            // 
            // label5
            // 
            this.label5.Font = new System.Drawing.Font("Dubai", 12F);
            this.label5.Location = new System.Drawing.Point(247, 250);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(100, 23);
            this.label5.TabIndex = 49;
            this.label5.Text = "Address";
            // 
            // label6
            // 
            this.label6.Font = new System.Drawing.Font("Dubai", 12F);
            this.label6.Location = new System.Drawing.Point(247, 286);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(100, 23);
            this.label6.TabIndex = 50;
            this.label6.Text = "Type";
            // 
            // lblCarPlate
            // 
            this.lblCarPlate.Font = new System.Drawing.Font("Dubai", 12F);
            this.lblCarPlate.Location = new System.Drawing.Point(247, 326);
            this.lblCarPlate.Name = "lblCarPlate";
            this.lblCarPlate.Size = new System.Drawing.Size(100, 23);
            this.lblCarPlate.TabIndex = 51;
            this.lblCarPlate.Text = "Type";
            this.lblCarPlate.Visible = false;
            // 
            // FrmStartBooking
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Info;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lblCarPlate);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btnBook);
            this.Controls.Add(this.btnCheck);
            this.Controls.Add(this.cmbCategories);
            this.Controls.Add(this.txtCarDetails);
            this.Controls.Add(this.txtCustAddress);
            this.Controls.Add(this.txtCustID);
            this.Controls.Add(this.txtCustName);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label3);
            this.MaximizeBox = false;
            this.Name = "FrmStartBooking";
            this.Text = "FrmStartBooking";
            this.Load += new System.EventHandler(this.FrmStartBooking_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.TextBox txtCustName;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.TextBox txtCustID;
        private System.Windows.Forms.TextBox txtCustAddress;
        private System.Windows.Forms.TextBox txtCarDetails;
        private System.Windows.Forms.ComboBox cmbCategories;
        private System.Windows.Forms.Button btnCheck;
        private System.Windows.Forms.Button btnBook;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lblCarPlate;
    }
}