// **************************************************
// Custom code for UD02Form
// Created: 4/3/2012 12:57:46 PM
// **************************************************
using System;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Windows.Forms;
using Epicor.Mfg.BO;
using Epicor.Mfg.UI;
using Epicor.Mfg.UI.Adapters;
using Epicor.Mfg.UI.Customization;
using Epicor.Mfg.UI.ExtendedProps;
using Epicor.Mfg.UI.FormFunctions;
using Epicor.Mfg.UI.FrameWork;
using Epicor.Mfg.UI.Searches;
using Epicor.Mfg.Core;
using Epicor.Mfg.Lib;
using Infragistics.Win.UltraWinGrid;

public class Script
{
	// ** Wizard Insert Location - Do Not Remove 'Begin/End Wizard Added Module Level Variables' Comments! **
	// Begin Wizard Added Module Level Variables **

	private EpiDataView edvUD02;
	private UD02Adapter oTrans_adapter;
	// End Wizard Added Module Level Variables **

	// Add Custom Module Level Variables Here **
	Epicor.Mfg.UI.App.UD02Entry.DetailPanel pnl;
	DynamicQuery _dq;
	BOReader _boReader;
	public void InitializeCustomCode()
	{
		// ** Wizard Insert Location - Do not delete 'Begin/End Wizard Added Variable Initialization' lines **
		// Begin Wizard Added Variable Initialization

		this.baseToolbarsManager.ToolClick += new Infragistics.Win.UltraWinToolbars.ToolClickEventHandler(this.baseToolbarsManager_ToolClick);
		this.UD02Form.Closing += new System.ComponentModel.CancelEventHandler(this.UD02Form_Closing);
		this.edvUD02 = ((EpiDataView)(this.oTrans.EpiDataViews["UD02"]));
		this.edvUD02.EpiViewNotification += new EpiViewNotification(this.edvUD02_EpiViewNotification);
		this.oTrans_adapter = ((UD02Adapter)(this.csm.TransAdaptersHT["oTrans_adapter"]));
		// End Wizard Added Variable Initialization

		// Begin Wizard Added Custom Method Calls

		this.btnJobNum.Click += new System.EventHandler(this.btnJobNum_Click);
		this.txtJobNum.Validating += new System.ComponentModel.CancelEventHandler(this.txtJobNum_Validating);
		_dq= new DynamicQuery(((Session)oTrans.Session).ConnectionPool);
		_boReader= new BOReader(((Session)oTrans.Session).ConnectionPool);
		this.grdJobData.AfterSelectChange += new Infragistics.Win.UltraWinGrid.AfterSelectChangeEventHandler(this.grdJobData_AfterSelectChange);
		this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
		this.grdLotTrackData.BeforeRowsDeleted += new Infragistics.Win.UltraWinGrid.BeforeRowsDeletedEventHandler(this.grdLotTrackData_BeforeRowsDeleted);
		this.grdLotTrackData.KeyDown += new System.Windows.Forms.KeyEventHandler(this.grdLotTrackData_KeyDown);
		this.grdLotTrackData.BeforeRowInsert += new Infragistics.Win.UltraWinGrid.BeforeRowInsertEventHandler(this.grdLotTrackData_BeforeRowInsert);
		this.btnRemove.Click += new System.EventHandler(this.btnRemove_Click);
		this.txtCopyFromJob.Validating += new System.ComponentModel.CancelEventHandler(this.txtCopyFromJob_Validating);
		this.btnCopy.Click += new System.EventHandler(this.btnCopy_Click);
		this.btnAddBt.Click += new System.EventHandler(this.btnAddBt_Click);
		CreateRowRuleUD02Character03CustomCondition_h();;
		CreateRowRuleUD02Key2CustomCondition_RED();;
		this.grdJobData.InitializeRow += new Infragistics.Win.UltraWinGrid.InitializeRowEventHandler(this.grdJobData_InitializeRow);
		// End Wizard Added Custom Method Calls
	}

	public void DestroyCustomCode()
	{
		// ** Wizard Insert Location - Do not delete 'Begin/End Wizard Added Object Disposal' lines **
		// Begin Wizard Added Object Disposal

		this.baseToolbarsManager.ToolClick -= new Infragistics.Win.UltraWinToolbars.ToolClickEventHandler(this.baseToolbarsManager_ToolClick);
		this.UD02Form.Closing -= new System.ComponentModel.CancelEventHandler(this.UD02Form_Closing);
		this.btnJobNum.Click -= new System.EventHandler(this.btnJobNum_Click);
		this.edvUD02.EpiViewNotification -= new EpiViewNotification(this.edvUD02_EpiViewNotification);
		this.edvUD02 = null;
		this.txtJobNum.Validating -= new System.ComponentModel.CancelEventHandler(this.txtJobNum_Validating);
		this.grdJobData.AfterSelectChange -= new Infragistics.Win.UltraWinGrid.AfterSelectChangeEventHandler(this.grdJobData_AfterSelectChange);
		this.btnAdd.Click -= new System.EventHandler(this.btnAdd_Click);
		this.grdLotTrackData.BeforeRowsDeleted -= new Infragistics.Win.UltraWinGrid.BeforeRowsDeletedEventHandler(this.grdLotTrackData_BeforeRowsDeleted);
		this.grdLotTrackData.KeyDown -= new System.Windows.Forms.KeyEventHandler(this.grdLotTrackData_KeyDown);
		this.grdLotTrackData.BeforeRowInsert -= new Infragistics.Win.UltraWinGrid.BeforeRowInsertEventHandler(this.grdLotTrackData_BeforeRowInsert);
		this.btnRemove.Click -= new System.EventHandler(this.btnRemove_Click);
		this.oTrans_adapter = null;
		this.txtCopyFromJob.Validating -= new System.ComponentModel.CancelEventHandler(this.txtCopyFromJob_Validating);
		this.btnCopy.Click -= new System.EventHandler(this.btnCopy_Click);
		this.btnAddBt.Click -= new System.EventHandler(this.btnAddBt_Click);
		this.grdJobData.InitializeRow -= new Infragistics.Win.UltraWinGrid.InitializeRowEventHandler(this.grdJobData_InitializeRow);
		// End Wizard Added Object Disposal

		// Begin Custom Code Disposal

		// End Custom Code Disposal
	}

	private void baseToolbarsManager_ToolClick(object sender, Infragistics.Win.UltraWinToolbars.ToolClickEventArgs args)
	{
	}

	private void UD02Form_Resize(object sender, EventArgs e)
	{
		/*int pnlWidth=pnl.Width;
		decimal widthOfItem = (pnlWidth-40)/3;
		grpLotTrackData.Width=(int)widthOfItem;
		grpBurnTestData.Width=(int)widthOfItem;
		grpJobData.Width=(int)widthOfItem;
		grpJobData.Left=10;
		grpBurnTestData.Left=grpJobData.Left+grpJobData.Width+10;
		grpLotTrackData.Left=grpBurnTestData.Left+grpBurnTestData.Width+10;*/
    }


	private void UD02Form_Load(object sender, EventArgs args)
	{
		// Add Event Handler Code
		UD02Form.Resize += new System.EventHandler(UD02Form_Resize);
		UD02Form.ResizeEnd += new System.EventHandler(this.UD02Form_Resize);
		UD02Form.MaximizeBox=false;
		pnl = (Epicor.Mfg.UI.App.UD02Entry.DetailPanel)csm.GetNativeControlReference("d5488fbc-e47b-46b6-aa3e-9ab7d923315a");
		grdJobData.Dock=System.Windows.Forms.DockStyle.Fill;
		grdBurnTestData.Dock=System.Windows.Forms.DockStyle.Fill;
		grdLotTrackData.Dock=System.Windows.Forms.DockStyle.Fill;
	}

	private void UD02Form_Closing(object sender, System.ComponentModel.CancelEventArgs args)
	{
		UD02Form.Resize -= new System.EventHandler(UD02Form_Resize);
		// Add Event Handler Code
	}


	private void SearchOnJobEntryAdapterShowDialog()
	{
		// Wizard Generated Search Method
		// You will need to call this method from another method in custom code
		// For example, [Form]_Load or [Button]_Click

		bool recSelected;
		string whereClause = "JobHead.JobClosed=false";
		System.Data.DataSet dsJobEntryAdapter = Epicor.Mfg.UI.FormFunctions.SearchFunctions.listLookup(this.oTrans, "JobEntryAdapter", out recSelected, true, whereClause);
		if (recSelected)
		{
			System.Data.DataRow adapterRow = dsJobEntryAdapter.Tables[0].Rows[0];

			// Map Search Fields to Application Fields
			txtJobNum.Text = adapterRow["JobNum"].ToString();
			txtJobNum.Focus();
			btnJobNum.Focus();
			
		}
	}

	private void btnJobNum_Click(object sender, System.EventArgs args)
	{
		// ** Place Event Handling Code Here **
		oTrans.Update();
		SearchOnJobEntryAdapterShowDialog();
		
	}

	private void edvUD02_EpiViewNotification(EpiDataView view, EpiNotifyArgs args)
	{
		// ** Argument Properties and Uses **
		// view.dataView[args.Row]["FieldName"]
		// args.Row, args.Column, args.Sender, args.NotifyType
		// NotifyType.Initialize, NotifyType.AddRow, NotifyType.DeleteRow, NotifyType.InitLastView, NotifyType.InitAndResetTreeNodes
		if ((args.NotifyType == EpiTransaction.NotifyType.AddRow))
		{
			if ((args.Row > -1))
			{
			}
		}
	}

	private void txtJobNum_Validating(object sender, System.ComponentModel.CancelEventArgs args)
	{
		// ** Place Event Handling Code Here **
		oTrans.Update();
		
		if(!String.IsNullOrEmpty(txtJobNum.Text))
		{
			QueryDesignDataSet dqds = null;
			dqds = _dq.GetByID("CIC68322-GetJobMtl1");
			//Replace the Query Criterion w/ your own 
			dqds.QueryWhereItem[0].RValue = txtJobNum.Text;
			DataSet ds = _dq.Execute(dqds);
			ds.Tables[0].Columns[0].Caption="Asm";
			ds.Tables[0].Columns[1].Caption="Asm PartNum";	
			ds.Tables[0].Columns[2].Caption="MTL P/N";
			grdJobData.DataSource=ds.Tables[0];
			string whereClause = "Key1='"+txtJobNum.Text+"'";
			System.Collections.Hashtable whereClauses = new System.Collections.Hashtable(1);
			whereClauses.Add("UD02", whereClause);
			SearchOptions searchOptions = SearchOptions.CreateRuntimeSearch(whereClauses, DataSetMode.RowsDataSet);
			oTrans_adapter.InvokeSearch(searchOptions);
			if ((oTrans_adapter.UD02Data.UD02.Rows.Count > 0))
			{
				edvUD02.Row = 0;
			} else
			{
				edvUD02.Row = -1;
			}
			edvUD02.Notify(new EpiNotifyArgs(oTrans, edvUD02.Row,edvUD02.Column));
			//oTrans_adapter.GetRows();
		}
	}

	private void grdJobData_AfterSelectChange(object sender, Infragistics.Win.UltraWinGrid.AfterSelectChangeEventArgs args)
	{
		// ** Place Event Handling Code Here **
		GetBTData();
	}


	private void GetBTData() 
	{
		try {
			if (grdJobData.Selected.Rows.Count > 0) {
				string baqID = "CIC68322-BurnTestData";
				DynamicQueryAdapter DQadpt = new DynamicQueryAdapter(UD02Form);
				DQadpt.BOConnect();
				
	
				Int32 topNRecords = 100000;
				bool hasMoreRecords = true;
				string resultFieldList = "";
	
				Epicor.Mfg.BO.QueryExecutionDataSet execSet = DQadpt.GetQueryExecutionParametersByID(baqID);
	
				DataRow targetRow = null;
				DataRow targetRow1 = null;
				DataTable tbl = execSet.Tables["ExecutionParameter"];
				
				
				targetRow = execSet.Tables["ExecutionParameter"].NewRow();
	
				targetRow["ParameterName"] = "MtlPartNum";
				targetRow["ParameterValue"] = grdJobData.Selected.Rows[0].Cells["JobMtl.PartNum"].Value.ToString() + "";
				targetRow["ValueType"] = "Character";
				targetRow["IsEmpty"] = false;
				targetRow["RowIdent"] = "A";
	
				tbl.Rows.Add(targetRow);
			
				DQadpt.ExecuteByIDParametrized(baqID, execSet, resultFieldList, topNRecords, out hasMoreRecords);
		
				grdBurnTestData.DataSource = DQadpt.QueryResults;
	
				setupBurnTestGrid(grdBurnTestData);

				oTrans.PushStatusText("", true);
			} else {
				oTrans.PushStatusText("No Job Data selected.", true);
			}
			
		} catch (Exception e) {
			MessageBox.Show("Unable to exec query: " + e.Message);
			oTrans.PushStatusText("Unable to retrieve BT data", true);
		}
	}



	private void setupBurnTestGrid(Epicor.Mfg.UI.FrameWork.EpiUltraGrid burnTestGrid) 
	{
		String msg = "";
	
		foreach (Infragistics.Win.UltraWinGrid.UltraGridColumn col in burnTestGrid.DisplayLayout.Bands[0].Columns) {
//			msg = msg + col.Key + " / " + col.Header.Caption + "\r\n";
			col.Hidden = true;
		}
		
		//MessageBox.Show(msg);

		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Company"].Hidden = true;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key1"].Hidden = false;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key2"].Hidden = true;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key3"].Hidden = true;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key4"].Hidden = true;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key5"].Hidden = true;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Character01"].Hidden = true;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Character02"].Hidden = false;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Character03"].Hidden = false;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Date01"].Hidden = false;
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.ShortChar02"].Hidden = false;

		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Company"].Header.Caption = "Company";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key1"].Header.Caption = "BT #";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key2"].Header.Caption = "Key2";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key3"].Header.Caption = "Key3";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key4"].Header.Caption = "Key4";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Key5"].Header.Caption = "Key5";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Character01"].Header.Caption = "Mtl P/N";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Character02"].Header.Caption = "Lot Num";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Character03"].Header.Caption = "Sup P/N";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Date01"].Header.Caption = "Date";
		burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.ShortChar02"].Header.Caption = "Plant";


		//burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Number01"].Format = "##,###,###0.00";

		//burnTestGrid.DisplayLayout.Bands[0].Columns["UD01.Number01"].CellAppearance.TextHAlign  = Infragistics.Win.HAlign.Right;

		burnTestGrid.DisplayLayout.Bands[0].Override.AllowUpdate = Infragistics.Win.DefaultableBoolean.False;
		burnTestGrid.DisplayLayout.Bands[0].Override.AllowDelete = Infragistics.Win.DefaultableBoolean.False;
		burnTestGrid.DisplayLayout.Override.RowAlternateAppearance.BackColor = System.Drawing.Color.AliceBlue;
	}


	private void btnAdd_Click(object sender, System.EventArgs args)
	{
		// ** Place Event Handling Code Here **
		if(grdBurnTestData.Selected.Rows.Count>0)
		{

			foreach(Infragistics.Win.UltraWinGrid.UltraGridRow r in grdBurnTestData.Selected.Rows)
			{
				String partNum = r.Cells["UD01.Character01"].Value.ToString();
				String BTNum = r.Cells["UD01.Key1"].Value.ToString();
				String LotNum = r.Cells["UD01.Character02"].Value.ToString();
				String SupPN = r.Cells["UD01.Character03"].Value.ToString();

				String JobNum = txtJobNum.Text;
				bool dup=false;
				foreach(UD02DataSet.UD02Row r2 in oTrans_adapter.UD02Data.UD02)
				{
						if(r2.Key3.Equals(BTNum)){
							dup=true;
							break;
						}
				}
				if(!dup){
					oTrans.GetNew(JobNum,partNum,BTNum,LotNum,"");
					foreach(DataRowView r1 in edvUD02.dataView)
					{
						if((string)r1["RowMod"] == "A")r1["Character03"] = SupPN;
					}
				}
		MessageBox.Show("POP: " + SupPN);
			}
			grdBurnTestData.DeleteSelectedRows(false);
			//oTrans.GetNew(1,
			
		}
		else
			MessageBox.Show("You must select at Least 1 Row from the Grid","Error",MessageBoxButtons.OK,MessageBoxIcon.Error);
		
	}
	private void grdLotTrackData_BeforeRowsDeleted(object sender, Infragistics.Win.UltraWinGrid.BeforeRowsDeletedEventArgs args)
	{
		// Event handling code generated by wizard.
		args.Cancel = true;
		try
		{
			this.oTrans.Delete();
		} catch (System.Exception )
		{
		}
	}

	private void grdLotTrackData_KeyDown(object sender, System.Windows.Forms.KeyEventArgs args)
	{
		// Event handling code generated by wizard.
		if ((args.KeyCode == Keys.Escape))
		{
			try
			{
				this.oTrans.Undo();
			} catch (System.Exception )
			{
			}
		}
	}

	private void grdLotTrackData_BeforeRowInsert(object sender, Infragistics.Win.UltraWinGrid.BeforeRowInsertEventArgs args)
	{
		// Event handling code generated by wizard.
		args.Cancel = true;
		this.oTrans.SetCurrentEvent(TransactionEvent.AddNewOnNewFromGrid);
		try
		{
			this.oTrans.GetNew();
		} catch (System.Exception )
		{
		}
	}

	private void btnRemove_Click(object sender, System.EventArgs args)
	{
		// ** Place Event Handling Code Here **
		oTrans.Delete();
		oTrans.Update();
		foreach(UltraGridRow r in grdJobData.Rows)
		{
			
				r.Appearance.BackColor=System.Drawing.Color.Red;
		
		}
		string whereClause = "Key1='"+txtJobNum.Text+"'";
		System.Collections.Hashtable whereClauses = new System.Collections.Hashtable(1);
		whereClauses.Add("UD02", whereClause);
		SearchOptions searchOptions = SearchOptions.CreateRuntimeSearch(whereClauses, DataSetMode.RowsDataSet);
		oTrans_adapter.InvokeSearch(searchOptions);
		if ((oTrans_adapter.UD02Data.UD02.Rows.Count > 0))
		{
			edvUD02.Row = 0;
		} else
		{
			edvUD02.Row = -1;
		}
		edvUD02.Notify(new EpiNotifyArgs(oTrans, edvUD02.Row,edvUD02.Column));
		GetBTData();
	}



	private void txtCopyFromJob_Validating(object sender, System.ComponentModel.CancelEventArgs args)
	{
		// ** Place Event Handling Code Here **
	}


	private DataTable GetCopyJobLotTrackedData(String copyJobNum) 
	{
		DataTable dt = null;

		try {

			string baqID = "CIC68322-GlobalLotTestData";
			DynamicQueryAdapter DQadpt = new DynamicQueryAdapter(UD02Form);
			DQadpt.BOConnect();

			Int32 topNRecords = 100000;
			bool hasMoreRecords = true;
			string resultFieldList = "";
			
			Epicor.Mfg.BO.QueryExecutionDataSet execSet = DQadpt.GetQueryExecutionParametersByID(baqID);

			DataRow targetRow = null;
			DataRow targetRow1 = null;
			DataTable tbl = execSet.Tables["ExecutionParameter"];
			
			targetRow = execSet.Tables["ExecutionParameter"].NewRow();

			targetRow["ParameterName"] = "CopyJobNum";
			targetRow["ParameterValue"] = copyJobNum + "";
			targetRow["ValueType"] = "Character";
			targetRow["IsEmpty"] = false;
			targetRow["RowIdent"] = "A";

			tbl.Rows.Add(targetRow);
		
			DQadpt.ExecuteByIDParametrized(baqID, execSet, resultFieldList, topNRecords, out hasMoreRecords);
	
			dt = DQadpt.QueryResults.Tables[0];
			
		} catch (Exception e) {
			MessageBox.Show("Unable to exec query: " + e.Message);
		}

		return dt;
	}


	private DataTable GetAddBTLotTrackedData(String BTNum) 
	{
		DataTable dt = null;

		try {

			string baqID = "CIC68322-GlobalBurnTestData";
			DynamicQueryAdapter DQadpt = new DynamicQueryAdapter(UD02Form);
			DQadpt.BOConnect();

			Int32 topNRecords = 100000;
			bool hasMoreRecords = true;
			string resultFieldList = "";
			
			Epicor.Mfg.BO.QueryExecutionDataSet execSet = DQadpt.GetQueryExecutionParametersByID(baqID);

			DataRow targetRow = null;
			DataRow targetRow1 = null;
			DataTable tbl = execSet.Tables["ExecutionParameter"];
			
			targetRow = execSet.Tables["ExecutionParameter"].NewRow();

			targetRow["ParameterName"] = "BTNum";
			targetRow["ParameterValue"] = BTNum + "";
			targetRow["ValueType"] = "Character";
			targetRow["IsEmpty"] = false;
			targetRow["RowIdent"] = "A";

			tbl.Rows.Add(targetRow);
		
			DQadpt.ExecuteByIDParametrized(baqID, execSet, resultFieldList, topNRecords, out hasMoreRecords);
	
			dt = DQadpt.QueryResults.Tables[0];
			
		} catch (Exception e) {
			MessageBox.Show("Unable to exec query: " + e.Message);
		}

		return dt;
	}

	private void btnCopy_Click(object sender, System.EventArgs args)
	{
		oTrans.PushStatusText("Copy Job Lot Data...", true);
		
		String msg = "";

		// ** Place Event Handling Code Here **
		if (!String.IsNullOrEmpty(txtCopyFromJob.Text) && !String.IsNullOrEmpty(txtJobNum.Text))
		{
			oTrans.PushStatusText("Copy Job Number Found...", true);

			DataTable dt = GetCopyJobLotTrackedData(txtCopyFromJob.Text);
			if (dt != null) {
	
				foreach(DataRow dr in dt.Rows)
				{
					msg = String.Format("Lot Data: {0}, {1}, {2}, {3}, {4}, {5}, {6}", dr["UD02.Company"], dr["UD02.Key1"], dr["UD02.Key2"], dr["UD02.Key3"], dr["UD02.Key4"], dr["UD02.Key5"], dr["UD02.Character03"]);
					oTrans.PushStatusText(msg, true);

					bool dup=false;
					foreach(UD02DataSet.UD02Row r2 in oTrans_adapter.UD02Data.UD02)
					{
						if (r2.Key2.Equals(dr["UD02.Key2"].ToString()) && 
								r2.Key3.Equals(dr["UD02.Key3"].ToString()) && 
								r2.Key4.Equals(dr["UD02.Key4"].ToString()) && 
								r2.Key5.Equals(dr["UD02.Key5"].ToString()) &&
								r2.Character03.Equals(dr["UD02.Character03"].ToString())

						   ){

							oTrans.PushStatusText(msg, true);
							dup=true;
							break;
						}
					}
					if(!dup)						{
						oTrans.GetNew(txtJobNum.Text,dr["UD02.Key2"].ToString(),dr["UD02.Key3"].ToString(),dr["UD02.Key4"].ToString(),"");
						//edvUD02.dataView[edvUD02.Row]["Character03"]="Copied By: "+((Session)oTrans.Session).UserID+" From Job: "+txtCopyFromJob.Text+" In Company: "+dr["UD02.Company"].ToString();
						edvUD02.Notify(new EpiNotifyArgs(oTrans,edvUD02.Row,edvUD02.Column));
					}
				}
			} else {
				MessageBox.Show("Now Lot Data found for Copy Job","Warning",MessageBoxButtons.OK,MessageBoxIcon.Warning);
			}
		}
		else {
			MessageBox.Show("You must have a Job To Copy from Selected","Error",MessageBoxButtons.OK,MessageBoxIcon.Error);
		}

		oTrans.PushStatusText("Copy Complete.", false);
	}


	private void btnAddBt_Click(object sender, System.EventArgs args)
	{
		oTrans.PushStatusText("Add BT to Lot Data...", true);
		
		String msg = "";

		// ** Place Event Handling Code Here **
		if (!String.IsNullOrEmpty(txtBTSearch.Text))
		{
			oTrans.PushStatusText("Add BT Number Found...", true);

			//DataTable dt = GetCopyJobLotTrackedData(txtCopyFromJob.Text);
			DataTable dt = GetAddBTLotTrackedData(txtBTSearch.Text);
			if (dt != null) {
				oTrans.PushStatusText("Found Add BT Lot Data...", true);
	
				String partNum = dt.Rows[0]["UD01.Character01"].ToString();
				String BTNum = dt.Rows[0]["UD01.Key1"].ToString();
				String LotNum = dt.Rows[0]["UD01.Character02"].ToString();
				String SupPN = dt.Rows[0]["UD01.Character03"].ToString();

				String JobNum = txtJobNum.Text;
	
				bool dup=false;
				foreach(UD02DataSet.UD02Row r2 in oTrans_adapter.UD02Data.UD02)
				{
					if(r2.Key3.Equals(BTNum)) {
						dup=true;
						break;
					}
				}
				if(!dup) {
					oTrans.GetNew(JobNum,partNum,BTNum,LotNum,"");
				}	
				GetBTData();
			} else {
				MessageBox.Show("Burn Test # Data found for BT Add","Warning",MessageBoxButtons.OK,MessageBoxIcon.Warning);
			}
		}
		else
			MessageBox.Show("You must enter a Burn Test # to Add","Error",MessageBoxButtons.OK,MessageBoxIcon.Error);
	}


	private void CreateRowRuleUD02Character03CustomCondition_h()
	{
		// Description: CopiedData
		// **** begin autogenerated code ****
		RuleAction warningUD02_RowAction = RuleAction.AddRowSettings(this.oTrans, "UD02", true, SettingStyle.Warning);
		RuleAction[] ruleActions = new RuleAction[] {
				warningUD02_RowAction};
		// Create RowRule and add to the EpiDataView.
		RowRule rrCreateRowRuleUD02Character03CustomCondition_h = new RowRule("UD02.Character03", new RowRuleConditionDelegate2(this.UD02Character03h_CustomRuleCondition), "h", ruleActions);
		((EpiDataView)(this.oTrans.EpiDataViews["UD02"])).AddRowRule(rrCreateRowRuleUD02Character03CustomCondition_h);
		// **** end autogenerated code ****
	}


	private bool UD02Character03h_CustomRuleCondition(Epicor.Mfg.UI.ExtendedProps.RowRuleDelegateArgs args)
	{
		bool result = false;
		// ** RowRuleDelegateArgs Properties: args.Arg1, args.Arg2, args.Context, args.Row
		// ** put Row Rule condition evaluation logic here
		
		return !String.IsNullOrEmpty(args.Arg1.ToString());
	}


	private void CreateRowRuleUD02Key2CustomCondition_RED()
	{
		// Description: NoMatchRow
		// **** begin autogenerated code ****
		RuleAction[] ruleActions = new RuleAction[0];
		// Create RowRule and add to the EpiDataView.
		// Dummy Context Object
		object contextObject = null;
		RowRule rrCreateRowRuleUD02Key2CustomCondition_RED = new RowRule("UD02.Key2", new RowRuleConditionDelegate2(this.UD02Key2RED_CustomRuleCondition), "RED", new RowRuleActionDelegate2(this.UD02Key2DelegateRED_CustomRuleAction), contextObject);
		((EpiDataView)(this.oTrans.EpiDataViews["UD02"])).AddRowRule(rrCreateRowRuleUD02Key2CustomCondition_RED);
		// **** end autogenerated code ****
	}


	private bool UD02Key2RED_CustomRuleCondition(Epicor.Mfg.UI.ExtendedProps.RowRuleDelegateArgs args)
	{
		bool result = false;
		// ** RowRuleDelegateArgs Properties: args.Arg1, args.Arg2, args.Context, args.Row
		// ** put Row Rule condition evaluation logic here
		
		foreach(UltraGridRow r in grdJobData.Rows)
		{
			
			if(r.Cells[2].Value.ToString().ToUpper().Equals(args.Arg1.ToString().ToUpper()))
			{
				r.Appearance.BackColor=System.Drawing.Color.White;
				
			}
			
		}
		return result;
	}


	private void UD02Key2DelegateRED_CustomRuleAction(Epicor.Mfg.UI.ExtendedProps.RowRuleDelegateArgs args)
	{
		// ** RowRuleDelegateArgs Properties: args.Arg1, args.Arg2, args.Context, args.Row
		// ** put custom Rule Action logic here
	}


	private void grdJobData_InitializeRow(object sender, Infragistics.Win.UltraWinGrid.InitializeRowEventArgs args)
	{
		// ** Place Event Handling Code Here **
		args.Row.Appearance.BackColor=System.Drawing.Color.Red;
	}

}
