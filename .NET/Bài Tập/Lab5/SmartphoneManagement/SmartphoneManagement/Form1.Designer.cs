namespace SmartphoneManagement
{
    partial class Form1
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
            this.picPhoneImage = new System.Windows.Forms.PictureBox();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnDetele = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnLoadExcel = new System.Windows.Forms.Button();
            this.btnLoadSQL = new System.Windows.Forms.Button();
            this.btnUpdateSource = new System.Windows.Forms.Button();
            this.dgwPhoneList = new System.Windows.Forms.DataGridView();
            this.colSmartPhoneID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colSmartPhoneName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colSmartPhoneType = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colAnnoucedDate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colPlatform = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colCamera = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colRAM = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colBattery = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colPrice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.picPhoneImage)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgwPhoneList)).BeginInit();
            this.SuspendLayout();
            // 
            // picPhoneImage
            // 
            this.picPhoneImage.Location = new System.Drawing.Point(1041, 150);
            this.picPhoneImage.Name = "picPhoneImage";
            this.picPhoneImage.Size = new System.Drawing.Size(100, 50);
            this.picPhoneImage.TabIndex = 0;
            this.picPhoneImage.TabStop = false;
            this.picPhoneImage.Click += new System.EventHandler(this.picPhoneImage_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(119, 308);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(75, 23);
            this.btnUpdate.TabIndex = 1;
            this.btnUpdate.Text = "Update";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnDetele
            // 
            this.btnDetele.Location = new System.Drawing.Point(200, 308);
            this.btnDetele.Name = "btnDetele";
            this.btnDetele.Size = new System.Drawing.Size(75, 23);
            this.btnDetele.TabIndex = 2;
            this.btnDetele.Text = "Detele";
            this.btnDetele.UseVisualStyleBackColor = true;
            this.btnDetele.Click += new System.EventHandler(this.btnDetele_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(38, 308);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 3;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnLoadExcel
            // 
            this.btnLoadExcel.Location = new System.Drawing.Point(38, 23);
            this.btnLoadExcel.Name = "btnLoadExcel";
            this.btnLoadExcel.Size = new System.Drawing.Size(134, 23);
            this.btnLoadExcel.TabIndex = 4;
            this.btnLoadExcel.Text = "Load Data From Excel";
            this.btnLoadExcel.UseVisualStyleBackColor = true;
            this.btnLoadExcel.Click += new System.EventHandler(this.btnLoadExcel_Click);
            // 
            // btnLoadSQL
            // 
            this.btnLoadSQL.Location = new System.Drawing.Point(250, 23);
            this.btnLoadSQL.Name = "btnLoadSQL";
            this.btnLoadSQL.Size = new System.Drawing.Size(134, 23);
            this.btnLoadSQL.TabIndex = 5;
            this.btnLoadSQL.Text = "Load Data From SQL";
            this.btnLoadSQL.UseVisualStyleBackColor = true;
            this.btnLoadSQL.Click += new System.EventHandler(this.btnLoadSQL_Click);
            // 
            // btnUpdateSource
            // 
            this.btnUpdateSource.Location = new System.Drawing.Point(475, 308);
            this.btnUpdateSource.Name = "btnUpdateSource";
            this.btnUpdateSource.Size = new System.Drawing.Size(139, 23);
            this.btnUpdateSource.TabIndex = 6;
            this.btnUpdateSource.Text = "Update To DataSource";
            this.btnUpdateSource.UseVisualStyleBackColor = true;
            this.btnUpdateSource.Click += new System.EventHandler(this.btnUpdateSource_Click);
            // 
            // dgwPhoneList
            // 
            this.dgwPhoneList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwPhoneList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.colSmartPhoneID,
            this.colSmartPhoneName,
            this.colSmartPhoneType,
            this.colAnnoucedDate,
            this.colPlatform,
            this.colCamera,
            this.colRAM,
            this.colBattery,
            this.colPrice});
            this.dgwPhoneList.Location = new System.Drawing.Point(38, 52);
            this.dgwPhoneList.MultiSelect = false;
            this.dgwPhoneList.Name = "dgwPhoneList";
            this.dgwPhoneList.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect;
            this.dgwPhoneList.Size = new System.Drawing.Size(941, 250);
            this.dgwPhoneList.TabIndex = 7;
            this.dgwPhoneList.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgwPhoneList_CellContentClick);
            // 
            // colSmartPhoneID
            // 
            this.colSmartPhoneID.DataPropertyName = "SmartPhoneID";
            this.colSmartPhoneID.HeaderText = "SmartPhoneID";
            this.colSmartPhoneID.Name = "colSmartPhoneID";
            // 
            // colSmartPhoneName
            // 
            this.colSmartPhoneName.DataPropertyName = "SmartPhoneName";
            this.colSmartPhoneName.HeaderText = "SmartPhoneName";
            this.colSmartPhoneName.Name = "colSmartPhoneName";
            // 
            // colSmartPhoneType
            // 
            this.colSmartPhoneType.DataPropertyName = "SmartPhoneType";
            this.colSmartPhoneType.HeaderText = "SmartPhoneType";
            this.colSmartPhoneType.Name = "colSmartPhoneType";
            // 
            // colAnnoucedDate
            // 
            this.colAnnoucedDate.DataPropertyName = "AnnoucedDate";
            this.colAnnoucedDate.HeaderText = "AnnoucedDate";
            this.colAnnoucedDate.Name = "colAnnoucedDate";
            // 
            // colPlatform
            // 
            this.colPlatform.DataPropertyName = "Platform";
            this.colPlatform.HeaderText = "Platform";
            this.colPlatform.Name = "colPlatform";
            // 
            // colCamera
            // 
            this.colCamera.DataPropertyName = "Camera";
            this.colCamera.HeaderText = "Camera";
            this.colCamera.Name = "colCamera";
            // 
            // colRAM
            // 
            this.colRAM.DataPropertyName = "RAM";
            this.colRAM.HeaderText = "RAM";
            this.colRAM.Name = "colRAM";
            // 
            // colBattery
            // 
            this.colBattery.DataPropertyName = "Battery";
            this.colBattery.HeaderText = "Battery";
            this.colBattery.Name = "colBattery";
            // 
            // colPrice
            // 
            this.colPrice.DataPropertyName = "Price";
            this.colPrice.HeaderText = "Price";
            this.colPrice.Name = "colPrice";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1214, 368);
            this.Controls.Add(this.dgwPhoneList);
            this.Controls.Add(this.btnUpdateSource);
            this.Controls.Add(this.btnLoadSQL);
            this.Controls.Add(this.btnLoadExcel);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.btnDetele);
            this.Controls.Add(this.btnUpdate);
            this.Controls.Add(this.picPhoneImage);
            this.Name = "Form1";
            this.Text = "Phone Management";
            ((System.ComponentModel.ISupportInitialize)(this.picPhoneImage)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgwPhoneList)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox picPhoneImage;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnDetele;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnLoadExcel;
        private System.Windows.Forms.Button btnLoadSQL;
        private System.Windows.Forms.Button btnUpdateSource;
        private System.Windows.Forms.DataGridView dgwPhoneList;
        private System.Windows.Forms.DataGridViewTextBoxColumn colSmartPhoneID;
        private System.Windows.Forms.DataGridViewTextBoxColumn colSmartPhoneName;
        private System.Windows.Forms.DataGridViewTextBoxColumn colSmartPhoneType;
        private System.Windows.Forms.DataGridViewTextBoxColumn colAnnoucedDate;
        private System.Windows.Forms.DataGridViewTextBoxColumn colPlatform;
        private System.Windows.Forms.DataGridViewTextBoxColumn colCamera;
        private System.Windows.Forms.DataGridViewTextBoxColumn colRAM;
        private System.Windows.Forms.DataGridViewTextBoxColumn colBattery;
        private System.Windows.Forms.DataGridViewTextBoxColumn colPrice;
    }
}

