
namespace CarRentalGUI.Forms
{
    partial class FrmViewBooking
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
            this.bookingsGV = new System.Windows.Forms.DataGridView();
            this.isCurrentlyBookDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.bookCodeDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.bookingBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.label3 = new System.Windows.Forms.Label();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            ((System.ComponentModel.ISupportInitialize)(this.bookingsGV)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bookingBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // bookingsGV
            // 
            this.bookingsGV.AutoGenerateColumns = false;
            this.bookingsGV.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.bookingsGV.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.isCurrentlyBookDataGridViewTextBoxColumn,
            this.bookCodeDataGridViewTextBoxColumn});
            this.bookingsGV.DataSource = this.bookingBindingSource;
            this.bookingsGV.Location = new System.Drawing.Point(233, 85);
            this.bookingsGV.Name = "bookingsGV";
            this.bookingsGV.Size = new System.Drawing.Size(246, 236);
            this.bookingsGV.TabIndex = 0;
            this.bookingsGV.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // isCurrentlyBookDataGridViewTextBoxColumn
            // 
            this.isCurrentlyBookDataGridViewTextBoxColumn.DataPropertyName = "IsCurrentlyBook";
            this.isCurrentlyBookDataGridViewTextBoxColumn.HeaderText = "IsCurrentlyBook";
            this.isCurrentlyBookDataGridViewTextBoxColumn.Name = "isCurrentlyBookDataGridViewTextBoxColumn";
            // 
            // bookCodeDataGridViewTextBoxColumn
            // 
            this.bookCodeDataGridViewTextBoxColumn.DataPropertyName = "BookCode";
            this.bookCodeDataGridViewTextBoxColumn.HeaderText = "BookCode";
            this.bookCodeDataGridViewTextBoxColumn.Name = "bookCodeDataGridViewTextBoxColumn";
            // 
            // bookingBindingSource
            // 
            this.bookingBindingSource.DataSource = typeof(CarRentalGUI.BL.Booking);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Old English Text MT", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(205, 24);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(308, 34);
            this.label3.TabIndex = 25;
            this.label3.Text = "Car Rental Management";
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(672, 73);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(32, 13);
            this.linkLabel1.TabIndex = 26;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Back";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // FrmViewBooking
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Info;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.bookingsGV);
            this.MaximizeBox = false;
            this.Name = "FrmViewBooking";
            this.Text = "FrmViewBooking";
            this.Load += new System.EventHandler(this.FrmViewBooking_Load);
            ((System.ComponentModel.ISupportInitialize)(this.bookingsGV)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bookingBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView bookingsGV;
        private System.Windows.Forms.DataGridViewTextBoxColumn isCurrentlyBookDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn bookCodeDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource bookingBindingSource;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.LinkLabel linkLabel1;
    }
}