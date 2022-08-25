
namespace LaptopManagement
{
    partial class LaptopManagementForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(LaptopManagementForm));
            this.dgvLapList = new System.Windows.Forms.DataGridView();
            this.colLaptopID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colLaptopName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colLaptopType = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colProductDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colProcessor = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colHDD = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colRAM = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colPrice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.picLapImage = new System.Windows.Forms.PictureBox();
            this.btnLoadExcel = new System.Windows.Forms.Button();
            this.btnLoadSQL = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnUpdateSource = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvLapList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picLapImage)).BeginInit();
            this.SuspendLayout();
            // 
            // dgvLapList
            // 
            this.dgvLapList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvLapList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.colLaptopID,
            this.colLaptopName,
            this.colLaptopType,
            this.colProductDate,
            this.colProcessor,
            this.colHDD,
            this.colRAM,
            this.colPrice});
            this.dgvLapList.Location = new System.Drawing.Point(18, 44);
            this.dgvLapList.Margin = new System.Windows.Forms.Padding(4);
            this.dgvLapList.MultiSelect = false;
            this.dgvLapList.Name = "dgvLapList";
            this.dgvLapList.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect;
            this.dgvLapList.Size = new System.Drawing.Size(968, 339);
            this.dgvLapList.TabIndex = 0;
            this.dgvLapList.EditingControlShowing += new System.Windows.Forms.DataGridViewEditingControlShowingEventHandler(this.dgvLapList_EditingControlShowing);
            this.dgvLapList.SelectionChanged += new System.EventHandler(this.dgvLapList_CellContentClick);
            // 
            // colLaptopID
            // 
            this.colLaptopID.DataPropertyName = "LaptopID";
            this.colLaptopID.HeaderText = "LaptopID";
            this.colLaptopID.Name = "colLaptopID";
            // 
            // colLaptopName
            // 
            this.colLaptopName.DataPropertyName = "LaptopName";
            this.colLaptopName.HeaderText = "Laptop Name";
            this.colLaptopName.Name = "colLaptopName";
            this.colLaptopName.Width = 160;
            // 
            // colLaptopType
            // 
            this.colLaptopType.DataPropertyName = "LaptopType";
            this.colLaptopType.HeaderText = "Laptop Type";
            this.colLaptopType.Name = "colLaptopType";
            // 
            // colProductDate
            // 
            this.colProductDate.DataPropertyName = "ProductDate";
            this.colProductDate.HeaderText = "Product Date";
            this.colProductDate.Name = "colProductDate";
            // 
            // colProcessor
            // 
            this.colProcessor.DataPropertyName = "Processor";
            this.colProcessor.HeaderText = "Processor";
            this.colProcessor.Name = "colProcessor";
            this.colProcessor.Width = 120;
            // 
            // colHDD
            // 
            this.colHDD.DataPropertyName = "HDD";
            this.colHDD.HeaderText = "HDD";
            this.colHDD.Name = "colHDD";
            // 
            // colRAM
            // 
            this.colRAM.DataPropertyName = "RAM";
            this.colRAM.HeaderText = "RAM";
            this.colRAM.Name = "colRAM";
            // 
            // colPrice
            // 
            this.colPrice.DataPropertyName = "Price";
            this.colPrice.HeaderText = "Price";
            this.colPrice.Name = "colPrice";
            this.colPrice.Width = 150;
            // 
            // picLapImage
            // 
            this.picLapImage.Image = ((System.Drawing.Image)(resources.GetObject("picLapImage.Image")));
            this.picLapImage.Location = new System.Drawing.Point(1003, 89);
            this.picLapImage.Margin = new System.Windows.Forms.Padding(4);
            this.picLapImage.Name = "picLapImage";
            this.picLapImage.Size = new System.Drawing.Size(316, 257);
            this.picLapImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picLapImage.TabIndex = 1;
            this.picLapImage.TabStop = false;
            // 
            // btnLoadExcel
            // 
            this.btnLoadExcel.Location = new System.Drawing.Point(18, 12);
            this.btnLoadExcel.Name = "btnLoadExcel";
            this.btnLoadExcel.Size = new System.Drawing.Size(237, 25);
            this.btnLoadExcel.TabIndex = 2;
            this.btnLoadExcel.Text = "Load Data From Excel";
            this.btnLoadExcel.UseVisualStyleBackColor = true;
            this.btnLoadExcel.Click += new System.EventHandler(this.btnLoadExcel_Click);
            // 
            // btnLoadSQL
            // 
            this.btnLoadSQL.Location = new System.Drawing.Point(322, 12);
            this.btnLoadSQL.Name = "btnLoadSQL";
            this.btnLoadSQL.Size = new System.Drawing.Size(237, 25);
            this.btnLoadSQL.TabIndex = 3;
            this.btnLoadSQL.Text = "Load Data From SQL";
            this.btnLoadSQL.UseVisualStyleBackColor = true;
            this.btnLoadSQL.Click += new System.EventHandler(this.btnLoadSQL_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(213, 391);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(82, 32);
            this.btnUpdate.TabIndex = 4;
            this.btnUpdate.Text = "Update";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(115, 391);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(82, 32);
            this.btnDelete.TabIndex = 5;
            this.btnDelete.Text = "Delete";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(18, 391);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(82, 31);
            this.btnAdd.TabIndex = 6;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnUpdateSource
            // 
            this.btnUpdateSource.Location = new System.Drawing.Point(414, 390);
            this.btnUpdateSource.Name = "btnUpdateSource";
            this.btnUpdateSource.Size = new System.Drawing.Size(213, 32);
            this.btnUpdateSource.TabIndex = 7;
            this.btnUpdateSource.Text = "Update To DataSource";
            this.btnUpdateSource.UseVisualStyleBackColor = true;
            this.btnUpdateSource.Click += new System.EventHandler(this.btnUpdateSource_Click);
            // 
            // LaptopManagementForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(1330, 464);
            this.Controls.Add(this.btnUpdateSource);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnUpdate);
            this.Controls.Add(this.btnLoadSQL);
            this.Controls.Add(this.btnLoadExcel);
            this.Controls.Add(this.picLapImage);
            this.Controls.Add(this.dgvLapList);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "LaptopManagementForm";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.RightToLeftLayout = true;
            this.Text = "Laptop Management";
            ((System.ComponentModel.ISupportInitialize)(this.dgvLapList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picLapImage)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dgvLapList;
        private System.Windows.Forms.PictureBox picLapImage;
        private System.Windows.Forms.Button btnLoadExcel;
        private System.Windows.Forms.Button btnLoadSQL;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnUpdateSource;
        private System.Windows.Forms.DataGridViewTextBoxColumn colLaptopID;
        private System.Windows.Forms.DataGridViewTextBoxColumn colLaptopName;
        private System.Windows.Forms.DataGridViewTextBoxColumn colLaptopType;
        private System.Windows.Forms.DataGridViewTextBoxColumn colProductDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn colProcessor;
        private System.Windows.Forms.DataGridViewTextBoxColumn colHDD;
        private System.Windows.Forms.DataGridViewTextBoxColumn colRAM;
        private System.Windows.Forms.DataGridViewTextBoxColumn colPrice;
    }
}

