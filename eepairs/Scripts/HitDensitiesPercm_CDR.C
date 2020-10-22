HitDensitiesPercm_CDR(){

  gStyle->SetOptStat(0);

  TFile *infile = new TFile("/afs/cern.ch/user/v/voutsina/Work/SR/Scripts/Results/Reconstruction/test.root","read");

  int VXDBrad[6];
  double VXDBrad_errors[6];
  double VXDBrad_wgt[6];
  double VXDBradErrors_wgt[6];
  double VXDLayers_radii[6]={12.5,14.5,35,37,57,59};
  double VXDLayers_area[6]={29354.84,29354.84,60545.4,60545.4,92379.2,92379.2};
  double zeros[6]={0.,0.,0.,0.,0.,0.};

  int testcounter1 = 0 ;
  int testcounter2 = 0 ;
  int testcounter3 = 0 ;
  int testcounter4 = 0 ;
  int testcounter5 = 0 ;
  int testcounter6 = 0 ;

  // declaration of plots for hit densities at VXD barrel
  TH1F *hzvxddens1= new TH1F("hz","VXD Barrel L1", 25,-125,125);
  hzvxddens1->Sumw2();
  hzvxddens1->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hzvxddens1->GetXaxis()->SetTitle("Z (mm)") ;
  hzvxddens1->SetMinimum(0.00000000001);
  TGaxis *myX = (TGaxis*)hzvxddens1->GetXaxis();
  myX->SetMaxDigits(1);
  //hzvxddens1->SetMaximum(0.8);
  hzvxddens1->SetLineColor(2);
  hzvxddens1->SetMarkerColor(2);
  TH1F *hzvxddens2= new TH1F("hz","VXD Barrel L2", 25,-125,125);
  hzvxddens2->Sumw2();
  hzvxddens2->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hzvxddens2->GetXaxis()->SetTitle("Z (mm)") ;
  hzvxddens2->SetMinimum(0.00000000001);
  hzvxddens2->SetMarkerColor(3);
  hzvxddens2->SetLineColor(3);
  //hzvxddens2->SetMaximum(0.8);
  TH1F *hzvxddens3= new TH1F("hz","VXD Barrel L3", 25,-125,125);
  hzvxddens3->Sumw2();
  hzvxddens3->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hzvxddens3->GetXaxis()->SetTitle("Z (mm)") ;
  hzvxddens3->SetMinimum(0.00000000001);
  hzvxddens3->SetMarkerColor(4);
  hzvxddens3->SetLineColor(4);
  //hzvxddens3->SetMaximum(0.8);
  TH1F *hzvxddens4= new TH1F("hz","VXD Barrel L4", 25,-125,125);
  hzvxddens4->Sumw2();
  hzvxddens4->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hzvxddens4->GetXaxis()->SetTitle("Z (mm)") ;
  hzvxddens4->SetMinimum(0.00000000001);
  hzvxddens4->SetMarkerColor(5);
  hzvxddens4->SetLineColor(5);
  //hzvxddens4->SetMaximum(0.8);
  TH1F *hzvxddens5= new TH1F("hz","VXD Barrel L5", 25,-125,125);
  hzvxddens5->Sumw2();
  hzvxddens5->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hzvxddens5->GetXaxis()->SetTitle("Z (mm)") ;
  hzvxddens5->SetMinimum(0.00000000001);
  hzvxddens5->SetMarkerColor(6);
  hzvxddens5->SetLineColor(6);
  TH1F *hzvxddens6= new TH1F("hz","VXD Barrel L5", 25,-125,125);
  hzvxddens6->Sumw2();
  hzvxddens6->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hzvxddens6->GetXaxis()->SetTitle("Z (mm)") ;
  hzvxddens6->SetMinimum(0.00000000001);
  hzvxddens6->SetMarkerColor(7);
  hzvxddens6->SetLineColor(7);

  TH1F *hzvxdhits1= new TH1F("hz","VXD Barrel L1", 25,-125,125);
  hzvxdhits1->Sumw2();
  hzvxdhits1->GetYaxis()->SetTitle("Hits") ;
  hzvxdhits1->GetXaxis()->SetTitle("Z (mm)") ;
  hzvxdhits1->SetMinimum(0.00000000001);
  TH1F *hzvxdhits2= new TH1F("hz","VXD Barrel L2", 25,-125,125);
  hzvxdhits2->Sumw2();
  hzvxdhits2->GetYaxis()->SetTitle("Hits") ;
  hzvxdhits2->GetXaxis()->SetTitle("Z (mm)") ;
  TH1F *hzvxdhits3= new TH1F("hz","VXD Barrel L3", 25,-125,125);
  hzvxdhits3->Sumw2();
  hzvxdhits3->GetYaxis()->SetTitle("Hits") ;
  hzvxdhits3->GetXaxis()->SetTitle("Z (mm)") ;
  TH1F *hzvxdhits4= new TH1F("hz","VXD Barrel L4", 25,-125,125);
  hzvxdhits4->Sumw2();
  hzvxdhits4->GetYaxis()->SetTitle("Hits") ;
  hzvxdhits4->GetXaxis()->SetTitle("Z (mm)") ;
  TH1F *hzvxdhits5= new TH1F("hz","VXD Barrel L5", 25,-125,125);
  hzvxdhits5->Sumw2();
  hzvxdhits5->GetYaxis()->SetTitle("Hits") ;
  hzvxdhits5->GetXaxis()->SetTitle("Z (mm)") ;
  TH1F *hzvxdhits6= new TH1F("hz","VXD Barrel L6", 25,-125,125);
  hzvxdhits6->Sumw2();

  // declaration of plots for hit densities at Tracker barrel
  TH1F *hztbdens1= new TH1F("hz","Tracker Barrel L1", 50,-1264.2,1264.2);
  hztbdens1->Sumw2();
  hztbdens1->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hztbdens1->GetXaxis()->SetTitle("Z (mm)") ;
  hztbdens1->SetMinimum(0.00000000001);
  //hztbdens1->SetMaximum(0.8);
  hztbdens1->SetLineColor(2);
  hztbdens1->SetMarkerColor(2);
  TH1F *hztbdens2= new TH1F("hz","Tracker Barrel L2", 50,-1264.2,1264.2);
  hztbdens2->Sumw2();
  hztbdens2->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hztbdens2->GetXaxis()->SetTitle("Z (mm)") ;
  hztbdens2->SetMinimum(0.00000000001);
  hztbdens2->SetMarkerColor(3);
  hztbdens2->SetLineColor(3);
  //hztbdens2->SetMaximum(0.8);
  TH1F *hztbdens3= new TH1F("hz","Tracker Barrel L3", 50,-1264.2,1264.2);
  hztbdens3->Sumw2();
  hztbdens3->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hztbdens3->GetXaxis()->SetTitle("Z (mm)") ;
  hztbdens3->SetMinimum(0.00000000001);
  hztbdens3->SetMarkerColor(4);
  hztbdens3->SetLineColor(4);
  //hztbdens3->SetMaximum(0.8);
  TH1F *hztbdens4= new TH1F("hz","Tracker Barrel L4", 50,-1264.2,1264.2);
  hztbdens4->Sumw2();
  hztbdens4->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hztbdens4->GetXaxis()->SetTitle("Z (mm)") ;
  hztbdens4->SetMinimum(0.00000000001);
  hztbdens4->SetMarkerColor(5);
  hztbdens4->SetLineColor(5);
  //hztbdens4->SetMaximum(0.8);
  TH1F *hztbdens5= new TH1F("hz","Tracker Barrel L5", 50,-1264.2,1264.2);
  hztbdens5->Sumw2();
  hztbdens5->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hztbdens5->GetXaxis()->SetTitle("Z (mm)") ;
  hztbdens5->SetMinimum(0.00000000001);
  hztbdens5->SetMarkerColor(6);
  hztbdens5->SetLineColor(6);
  TH1F *hztbdens6= new TH1F("hz","Tracker Barrel L5", 50,-1264.2,1264.2);
  hztbdens6->Sumw2();
  hztbdens6->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hztbdens6->GetXaxis()->SetTitle("Z (mm)") ;
  hztbdens6->SetMinimum(0.00000000001);
  hztbdens6->SetMarkerColor(7);
  hztbdens6->SetLineColor(7);

  TH1F *hztbhits1= new TH1F("hz","Tracker Barrel L1", 50,-1264.2,1264.2);
  hztbhits1->Sumw2();
  hztbhits1->GetYaxis()->SetTitle("Hits") ;
  hztbhits1->GetXaxis()->SetTitle("Z (mm)") ;
  hztbhits1->SetMinimum(0.00000000001);
  TH1F *hztbhits2= new TH1F("hz","Tracker Barrel L2", 50,-1264.2,1264.2);
  hztbhits2->Sumw2();
  hztbhits2->GetYaxis()->SetTitle("Hits") ;
  hztbhits2->GetXaxis()->SetTitle("Z (mm)") ;
  TH1F *hztbhits3= new TH1F("hz","Tracker Barrel L3", 50,-1264.2,1264.2);
  hztbhits3->Sumw2();
  hztbhits3->GetYaxis()->SetTitle("Hits") ;
  hztbhits3->GetXaxis()->SetTitle("Z (mm)") ;
  TH1F *hztbhits4= new TH1F("hz","Tracker Barrel L4", 50,-1264.2,1264.2);
  hztbhits4->Sumw2();
  hztbhits4->GetYaxis()->SetTitle("Hits") ;
  hztbhits4->GetXaxis()->SetTitle("Z (mm)") ;
  TH1F *hztbhits5= new TH1F("hz","Tracker Barrel L5", 50,-1264.2,1264.2);
  hztbhits5->Sumw2();
  hztbhits5->GetYaxis()->SetTitle("Hits") ;
  hztbhits5->GetXaxis()->SetTitle("Z (mm)") ;
  TH1F *hztbhits6= new TH1F("hz","Tracker Barrel L6", 50,-1264.2,1264.2);
  hztbhits6->Sumw2();


  // declaration of plots for VXD Endcaps
  TH1F *hzvxdECHits1= new TH1F("hz","VXD Endcap D1",55,0,110);
  hzvxdECHits1 ->Sumw2();
  hzvxdECHits1->GetYaxis()->SetTitle("Hits ") ;
  hzvxdECHits1->GetXaxis()->SetTitle("Radius (mm)") ;
  hzvxdECHits1->GetXaxis()->SetLimits(0.,110.) ;
  TH1F *hzvxdECdens1= new TH1F("hz","VXD Endcap D1",55,0,110);
  hzvxdECdens1->Sumw2();
  hzvxdECdens1->GetYaxis()->SetTitle("hits / mm^{2} / BX ") ;
  hzvxdECdens1->GetXaxis()->SetTitle("Radius (mm)") ;
  hzvxdECdens1->GetXaxis()->SetLimits(0.,110.) ;
  hzvxdECdens1->SetMarkerColor(2);
  hzvxdECdens1->SetLineColor(2);
  TH1F *hzvxdECHits2= new TH1F("hz","VXD Endcap D2",55,0,110);
  hzvxdECHits2 ->Sumw2();
  hzvxdECHits2->GetYaxis()->SetTitle("Hits ") ;
  hzvxdECHits2->GetXaxis()->SetTitle("Radius (mm)") ;
  TH1F *hzvxdECdens2= new TH1F("hz","VXD Endcap D2",55,0,110);
  hzvxdECdens2 ->Sumw2();
  hzvxdECdens2->GetYaxis()->SetTitle("hits / mm^{2} / BX ") ;
  hzvxdECdens2->GetXaxis()->SetTitle("Radius (mm)") ;
  hzvxdECdens2->SetMarkerColor(3);
  hzvxdECdens2->SetLineColor(3);
  TH1F *hzvxdECHits6= new TH1F("hz","VXD Endcap D6",55,0,110);
  hzvxdECHits6 ->Sumw2();
  hzvxdECHits6->GetYaxis()->SetTitle("Hits ") ;
  hzvxdECHits6->GetXaxis()->SetTitle("Radius (mm)") ;
  TH1F *hzvxdECdens6= new TH1F("hz","VXD Endcap D6",55,0,110);
  hzvxdECdens6 ->Sumw2();
  hzvxdECdens6->GetYaxis()->SetTitle("hits / mm^{2} / BX ") ;
  hzvxdECdens6->GetXaxis()->SetTitle("Radius (mm)") ;
  hzvxdECdens6->SetMarkerColor(4);
  hzvxdECdens6->SetLineColor(4);
  TH1F *hzvxdECHits3= new TH1F("hz","VXD Endcap D3",55,0,110);
  hzvxdECHits3->Sumw2();
  hzvxdECHits3->GetYaxis()->SetTitle("Hits ") ;
  hzvxdECHits3->GetXaxis()->SetTitle("Radius (mm)") ;
  TH1F *hzvxdECdens3= new TH1F("hz","VXD Endcap D3",55,0,110);
  hzvxdECdens3->Sumw2();
  hzvxdECdens3->GetYaxis()->SetTitle("hits / mm^{2} / BX ") ;
  hzvxdECdens3->GetXaxis()->SetTitle("Radius (mm)") ;
  hzvxdECdens3->SetMarkerColor(5);
  hzvxdECdens3->SetLineColor(5);
  TH1F *hzvxdECHits4= new TH1F("hz","VXD Endcap D4",55,0,110);
  hzvxdECHits4->Sumw2();
  hzvxdECHits4->GetYaxis()->SetTitle("Hits ") ;
  hzvxdECHits4->GetXaxis()->SetTitle("Radius (mm)") ;
  TH1F *hzvxdECdens4= new TH1F("hz","VXD Endcap D4",55,0,110);
  hzvxdECdens4->Sumw2();
  hzvxdECdens4->GetYaxis()->SetTitle("hits / mm^{2} / BX ") ;
  hzvxdECdens4->GetXaxis()->SetTitle("Radius (mm)") ;
  hzvxdECdens4->SetMarkerColor(6);
  hzvxdECdens4->SetLineColor(6);
  TH1F *hzvxdECHits5= new TH1F("hz","VXD Endcap D5",55,0,110);
  hzvxdECHits5->Sumw2();
  hzvxdECHits5->GetYaxis()->SetTitle("Hits ") ;
  hzvxdECHits5->GetXaxis()->SetTitle("Radius (mm)") ;
  TH1F *hzvxdECdens5= new TH1F("hz","VXD Endcap D5",55,0,110);
  hzvxdECdens5->Sumw2();
  hzvxdECdens5->GetYaxis()->SetTitle("hits / mm^{2} / BX ") ;
  hzvxdECdens5->GetXaxis()->SetTitle("Radius (mm)") ;
  hzvxdECdens5->SetMarkerColor(7);
  hzvxdECdens5->SetLineColor(7);

  // declaration of plots for tracker endcaps
  TH1F *hitedens1= new TH1F("hz","ITE D1", 110,0,2200);
  hitedens1->Sumw2();
  hitedens1->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens1->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens1->GetXaxis()->SetLimits(0.,2200.) ;
  hitedens1->SetMarkerColor(2);
  hitedens1->SetLineColor(2);
  hitedens1->SetMaximum(0.001);
  TH1F *hitedens2= new TH1F("hz","ITE D2", 110,0,2200);
  hitedens2->Sumw2();
  hitedens2->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens2->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens2->SetMarkerColor(3);
  hitedens2->SetLineColor(3);
  TH1F *hitedens3= new TH1F("hz","ITE D3", 110,0,2200);
  hitedens3->Sumw2();
  hitedens3->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens3->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens3->SetMarkerColor(4);
  hitedens3->SetLineColor(4);
  TH1F *hitedens4= new TH1F("hz","ITE D4", 110,0,2200);  
  hitedens4->Sumw2();
  hitedens4->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens4->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens4->SetMarkerColor(5);
  hitedens4->SetLineColor(5);
  TH1F *hitedens5= new TH1F("hz","ITE D5", 110,0,2200);
  hitedens5->Sumw2();
  hitedens5->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens5->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens5->SetMarkerColor(6);
  hitedens5->SetLineColor(6);
  TH1F *hitedens6= new TH1F("hz","ITE D6", 110,0,2200);
  hitedens6->Sumw2();
  hitedens6->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens6->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens6->SetMarkerColor(7);
  hitedens6->SetLineColor(7);
  TH1F *hitedens7= new TH1F("hz","ITE D7", 110,0,2200);
  hitedens7->Sumw2();
  hitedens7->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens7->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens7->SetMarkerColor(8);
  hitedens7->SetLineColor(8);
  TH1F *hitedens8= new TH1F("hz","OTE D1", 110,0,2200);
  hitedens8->Sumw2();
  hitedens8->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens8->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens8->SetMarkerColor(29);
  hitedens8->SetLineColor(29);
  TH1F *hitedens9= new TH1F("hz","OTE D2", 110,0,2200);
  hitedens9->Sumw2();
  hitedens9->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens9->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens9->SetMarkerColor(38);
  hitedens9->SetLineColor(38);
  TH1F *hitedens10= new TH1F("hz","OTE D3", 110,0,2200);
  hitedens10->Sumw2();
  hitedens10->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens10->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens10->SetMarkerColor(46);
  hitedens10->SetLineColor(46);
  TH1F *hitedens11= new TH1F("hz","OTE D4", 110,0,2200);
  hitedens11->Sumw2();
  hitedens11->GetYaxis()->SetTitle("hits / mm^{2} / BX") ;
  hitedens11->GetXaxis()->SetTitle("Radius (mm)") ;
  hitedens11->SetMarkerColor(49);
  hitedens11->SetLineColor(49);
  TH1F *hitehits1= new TH1F("hz","ITE D1", 110,0,2200);
  hitehits1->Sumw2();
  hitehits1->GetYaxis()->SetTitle("hits") ;
  hitehits1->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits1->SetMarkerColor(2);
  hitehits1->SetLineColor(2);
  hitehits1->GetXaxis()->SetLimits(0.,2200.) ;  
  //hitehits1->SetMaximum(5.5);
  TH1F *hitehits2= new TH1F("hz","ITE D2", 110,0,2200);
  hitehits2->Sumw2();
  hitehits2->GetYaxis()->SetTitle("hits") ;
  hitehits2->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits2->SetMarkerColor(3);
  hitehits2->SetLineColor(3);
  TH1F *hitehits3= new TH1F("hz","ITE D3", 110,0,2200);
  hitehits3->Sumw2();
  hitehits3->GetYaxis()->SetTitle("hits") ;
  hitehits3->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits3->SetMarkerColor(4);
  hitehits3->SetLineColor(4);
  TH1F *hitehits4= new TH1F("hz","ITE D4", 110,0,2200);  
  hitehits4->Sumw2();
  hitehits4->GetYaxis()->SetTitle("hits") ;
  hitehits4->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits4->SetMarkerColor(5);
  hitehits4->SetLineColor(5);
  TH1F *hitehits5= new TH1F("hz","ITE D5", 110,0,2200);
  hitehits5->Sumw2();
  hitehits5->GetYaxis()->SetTitle("hits") ;
  hitehits5->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits5->SetMarkerColor(6);
  hitehits5->SetLineColor(6);
  TH1F *hitehits6= new TH1F("hz","ITE D6", 110,0,2200);
  hitehits6->Sumw2();
  hitehits6->GetYaxis()->SetTitle("hits") ;
  hitehits6->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits6->SetMarkerColor(7);
  hitehits6->SetLineColor(7);
  TH1F *hitehits7= new TH1F("hz","ITE D7", 110,0,2200);
  hitehits7->Sumw2();
  hitehits7->GetYaxis()->SetTitle("hits") ;
  hitehits7->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits7->SetMarkerColor(8);
  hitehits7->SetLineColor(8);
  TH1F *hitehits8= new TH1F("hz","OTE D1", 110,0,2200);
  hitehits8->Sumw2();
  hitehits8->GetYaxis()->SetTitle("hits") ;
  hitehits8->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits8->SetMarkerColor(29);
  hitehits8->SetLineColor(29);
  TH1F *hitehits9= new TH1F("hz","OTE D2", 110,0,2200);
  hitehits9->Sumw2();
  hitehits9->GetYaxis()->SetTitle("hits") ;
  hitehits9->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits9->SetMarkerColor(38);
  hitehits9->SetLineColor(38);
  TH1F *hitehits10= new TH1F("hz","OTE D3", 110,0,2200);
  hitehits10->Sumw2();
  hitehits10->GetYaxis()->SetTitle("hits") ;
  hitehits10->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits10->SetMarkerColor(46);
  hitehits10->SetLineColor(46);
  TH1F *hitehits11= new TH1F("hz","OTE D4", 110,0,2200);
  hitehits11->Sumw2();
  hitehits11->GetYaxis()->SetTitle("hits") ;
  hitehits11->GetXaxis()->SetTitle("Radius (mm)") ;
  hitehits11->SetMarkerColor(49);
  hitehits11->SetLineColor(49);




  TCanvas *c = new TCanvas("cvxdb","Density @ VXD barrel",800,800);
  TCanvas *c2 = new TCanvas("ctb","Density @ Tracker barrel",800,800);
  TCanvas *c3 = new TCanvas("cvxdec","Density @ VXD endcap",800,800);
  TCanvas *c4 = new TCanvas("cte","Density @ Tracker endcaps",800,800);
  TCanvas *c5 = new TCanvas("c5","Density @ Tracker barrel vs R",800,800);
  TCanvas *ctest = new TCanvas("ctest","test purposes: hits in ITE D1",800,800);
  ctest->Divide(1,2);

  TTree *t1 = (TTree*)infile->Get("hits");

  //vector<int> *vxdlayer = new vector<int>();
  vector<int> *layer = new vector<int>();
  vector<int> *subdet = new vector<int>();
  vector<double> *simZ = new vector<double>();
  vector<double> *simX = new vector<double>();
  vector<double> *simY = new vector<double>();
  vector<double> *simEffPathLength = new vector<double>();
  vector<bool> *Secondary = new vector<bool>();
  vector<double> *hitTime = new vector<double>();

  //t1->SetBranchAddress("vxdlayer",&vxdlayer);
  t1->SetBranchAddress("layer",&layer);
  t1->SetBranchAddress("subdet",&subdet);
  t1->SetBranchAddress("simZ",&simZ);
  t1->SetBranchAddress("simY",&simY);
  t1->SetBranchAddress("simX",&simX);
  t1->SetBranchAddress("simEffPathLength",&simEffPathLength);
  t1->SetBranchAddress("hitTime",&hitTime);
  t1->SetBranchAddress("Secondary",&Secondary);

  double PI = (double)acos((double)(-1.0)) ;

  int nentries = t1->GetEntries();
  //int nentries = 80 ;
  cout << " no of entries " << nentries << endl ;
  for (int i=0; i<nentries; i++){

    t1->GetEntry(i);

    ////cout << " taking entry " << i << endl ;
    
    for (int j = 0 ; j < simZ->size() ; j++ ){

      if (subdet->at(j) == 1){                          // studying VXD barrel

	// loop on VXD barrel layers
	if (layer->at(j)==0){   
	  hzvxdhits1->Fill(simZ->at(j),1.);                         
	  double area = 29354.84;   // area of the VXD ladders in mm2
	  area = area/25. ;  // area of the specific bin
	  //std::cout << " area = " << area << std::endl ;
	  hzvxddens1->Fill(simZ->at(j),1./(area*nentries));    // hit density
	  hzvxddens1->GetYaxis()->SetTitleOffset(1.41);
	  //VXDBrad[0]++;
	  testcounter1++;
	}    
	if (layer->at(j)==1){  
	  hzvxdhits2->Fill(simZ->at(j),1.);                          
	  double area = 29354.84 ;
	  area = area/25. ;  // area of the specific bin
	  hzvxddens2->Fill(simZ->at(j),1./(area*nentries)); 
	  testcounter2++;
	}   
	// 2nd VXD barrel superlayer
	if (layer->at(j)==2){   
	  hzvxdhits3->Fill(simZ->at(j),1.);                         
	  double area = 60545.4;
	  area = area/25. ;  // area of the specific bin
	  hzvxddens3->Fill(simZ->at(j),1./(area*nentries));    // hit density
	  testcounter3++;
	}    
	if (layer->at(j)==3){   
	  hzvxdhits4->Fill(simZ->at(j),1.);                         
	  double area = 60545.4;
	  area = area/25. ;  // area of the specific bin
	  hzvxddens4->Fill(simZ->at(j),1./(area*nentries));    // hit density
	  testcounter4++;
	}   
	//3rd barrel superlayer
	if (layer->at(j)==4){                          
	  hzvxdhits5->Fill(simZ->at(j),1.);  
	  double area = 92379.2;
	  area = area/25. ;  // area of the specific bin
	  hzvxddens5->Fill(simZ->at(j),1./(area*nentries));    // hit density
	  testcounter5++;
	}    
	if (layer->at(j)==5){                          
	  hzvxdhits6->Fill(simZ->at(j),1.);  
	  double area = 92379.2;
	  area = area/25. ;  // area of the specific bin
	  hzvxddens6->Fill(simZ->at(j),1./(area*nentries));    // hit density
	  testcounter6++;
	}  
      }      // end of studying VXD barrel  

      // Study of barrel tracker
      if (subdet->at(j) == 3){     // study of inner tracker barrel
	if (layer->at(j)==0){   
	  hztbhits1->Fill(simZ->at(j),1.);                         
	  double area = 40351.47;   
	  hztbdens1->Fill(simZ->at(j),1./(area*nentries));    // hit density
	  hztbdens1->GetYaxis()->SetTitleOffset(1.41);
	  double firstBin = hztbdens1->GetBinContent(16);
	  hztbdens1->SetBinContent(16,firstBin*1.9);
	  double lastBin = hztbdens1->GetBinContent(35);
	  hztbdens1->SetBinContent(35,firstBin*1.9);	  	  
	}    
	if (layer->at(j)==1){  
	  hztbhits2->Fill(simZ->at(j),1.);                          
	  double area = 127091.25 ;
	  hztbdens2->Fill(simZ->at(j),1./(area*nentries));
	  double firstBin = hztbdens2->GetBinContent(16);
	  hztbdens2->SetBinContent(16,firstBin*1.9);
	  double lastBin = hztbdens2->GetBinContent(35);
	  hztbdens2->SetBinContent(35,firstBin*1.9);	 
	}   
	if (layer->at(j)==2){   
	  hztbhits3->Fill(simZ->at(j),1.);                         
	  double area = 212877.84;
	  hztbdens3->Fill(simZ->at(j),1./(area*nentries));    // hit density
	  double firstBin = hztbdens3->GetBinContent(12);
	  hztbdens3->SetBinContent(12,firstBin*1.5);
	  double lastBin = hztbdens3->GetBinContent(39);
	  hztbdens3->SetBinContent(39,firstBin*1.5);	  
	}    
      }   // end of studying ITB

      if (subdet->at(j) == 5){      // study of outer tracker barrel
	if (layer->at(j)==0){   
	  hztbhits4->Fill(simZ->at(j),1.);                         
	  double area = 317728.1;
	  hztbdens4->Fill(simZ->at(j),1./(area*nentries));    // hit density
	}   
	if (layer->at(j)==1){                          
	  hztbhits5->Fill(simZ->at(j),1.);  
	  double area = 498187.68;
	  hztbdens5->Fill(simZ->at(j),1./(area*nentries));    // hit density
	}    
	if (layer->at(j)==2){                          
	  hztbhits6->Fill(simZ->at(j),1.);  
	  double area = 678667.25;
	  hztbdens6->Fill(simZ->at(j),1./(area*nentries));    // hit density
	}  
      }      // end of studying outer tracker barrel  

      if (subdet->at(j) == 2){                          // studying VXD endcap
	
	// loop on VXD endcap layers
	
	double Rmax = 102.;
	double Rmin = 24.;
	int segs = 39 ;
	
	double PixelArea = 0.0004 ;
	
	for (int n = 1 ; n < segs +1 ; n++){
	  
	  double r  = Rmin + n*(Rmax - Rmin)/(segs*1.) ;
	  double rinn  = r - (Rmax - Rmin)/(segs*1.) ;
	  double area = 2*(PI*r*r - PI*rinn*rinn);  // x2 cause we have 2 discs
	  double channels = area / PixelArea ;
	  double Radius = sqrt(simX->at(j)*simX->at(j) + simY->at(j)*simY->at(j)) ;
	  //std::cout << "n " << n << " Outer radius " << r << " Inner radius " << rinn << " area " << area << " HIT RADIUS " << Radius << std::endl ;

	  if (Radius < r && Radius > rinn ) {
	    if (layer->at(j)==0){   
	      hzvxdECdens1->Fill(Radius,1.0/(area*1*nentries));    // hit density
	      hzvxdECHits1->Fill(Radius,(1.));
	      //std::cout << " I add the hit now " << std::endl ;
	      double firstBin = hzvxdECdens1->GetBinContent(13);
	      hzvxdECdens1->SetBinContent(13,firstBin*1.5);	      
	    }    
	    if (layer->at(j)==1){                          
	      hzvxdECdens2->Fill(Radius,1.0/(area*1*nentries));    // hit density
	      hzvxdECHits2->Fill(Radius,(1.));
	      //std::cout << " First set of discs: Radius " << Radius << " area " << area << std::endl ;
	      double firstBin = hzvxdECdens2->GetBinContent(13);
	      hzvxdECdens2->SetBinContent(13,firstBin*1.5);	      
	    }   
	    if (layer->at(j)==2){   
	      if (n==6){area=664.44;}                       
	      hzvxdECdens3->Fill(Radius,1.0/(area*1*nentries));    // hit density
	      hzvxdECHits3->Fill(Radius,(1.));
	      double firstBin = hzvxdECdens3->GetBinContent(18);
	      hzvxdECdens3->SetBinContent(18,firstBin*2.0);	      
	    }    
	    if (layer->at(j)==3){  
	      if (n==6){area=664.44;}                               
	      hzvxdECdens4->Fill(Radius,1.0/(area*1*nentries));    // hit density
	      hzvxdECHits4->Fill(Radius,(1.));
	      double firstBin = hzvxdECdens4->GetBinContent(18);
	      hzvxdECdens4->SetBinContent(18,firstBin*2.0);	      
	      //std::cout << "n " << n << " Hit radius " << Radius << " Second set of discs: Radius " << Radius << " area " << area << std::endl ;
	    }   
	    if (layer->at(j)==4){     
	      if (n==11){area=571.77;}                              
	      hzvxdECdens5->Fill(Radius,1.0/(area*1*nentries));    // hit density
	      hzvxdECHits5->Fill(Radius,(1.));
	      double firstBin = hzvxdECdens5->GetBinContent(23);
	      hzvxdECdens5->SetBinContent(23,firstBin*2.4);	     
	      //std::cout << "n " << n << " Hit radius " << Radius << " Third set of discs: Radius " << Radius << " area " << area << std::endl ;
	    }    
	    if (layer->at(j)==5){  
	      if (n==11){area=571.77;}                                 
	      hzvxdECdens6->Fill(Radius,1.0/(area*1*nentries));    // hit density
	      hzvxdECHits6->Fill(Radius,(1.));
	      double firstBin = hzvxdECdens6->GetBinContent(23);
	      hzvxdECdens6->SetBinContent(23,firstBin*2.4);	      
	      //std::cout << "n " << n << " Hit radius " << Radius << " Third set of discs: Radius " << Radius << " area " << area << std::endl ;
	    }  
	  } // end condition Radius
	}  // end loop on various radii values
      }   // end of studying VXD endcap 
      


      // Tracker endcaps
      double Rmax = 2190.;
      double Rmin = 78.;
      int segs = 80 ;

      for (int n = 1 ; n < segs +1 ; n++){	  

	double r  = Rmin + n*(Rmax - Rmin)/(segs*1.) ;
	double rinn  = r - (Rmax - Rmin)/(segs*1.) ;
	double area = 2*(PI*r*r - PI*rinn*rinn);
	double Radius = sqrt(simX->at(j)*simX->at(j) + simY->at(j)*simY->at(j)) ;

      //----------------------------------------------------------------
      // -- ITE---------------------------------------------------------

	if (subdet->at(j) == 4){ 

	  if (Radius < r && Radius > rinn ) {
	    if (layer->at(j)==0){   	      
	      hitedens1->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitedens1->GetYaxis()->SetTitleOffset(1.41);
	      hitehits1->Fill(Radius,(1.));
	      double firstBin = hitedens1->GetBinContent(4);
	      hitedens1->SetBinContent(4,firstBin*3.*35.184);
	    }
	    if (layer->at(j)==1){   
	      //std::cout << " Rin " << rinn << " Rout " << r << " area = " << area << std::endl ;	      
	      hitedens2->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits2->Fill(Radius,(1.));
	      double firstBin = hitedens2->GetBinContent(7);
	      hitedens2->SetBinContent(7,firstBin*1.2.*1.1);
	    }
	    if (layer->at(j)==2){  
	      //std::cout << " Rin " << rinn << " Rout " << r << " area = " << area << std::endl ; 	      
	      hitedens3->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits3->Fill(Radius,(1.));
	      double firstBin = hitedens3->GetBinContent(9);
	      hitedens3->SetBinContent(9,firstBin*1.3*1.1);
	    }
	    if (layer->at(j)==3){   	      
	      hitedens4->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits4->Fill(Radius,(1.));
	      double firstBin = hitedens4->GetBinContent(11);
	      hitedens4->SetBinContent(11,firstBin*1.6*1.1);
	    }
	    if (layer->at(j)==4){   	      
	      hitedens5->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits5->Fill(Radius,(1.));
	      double firstBin = hitedens5->GetBinContent(13);
	      hitedens5->SetBinContent(13,firstBin*1.9*1.1);
	    }
	    if (layer->at(j)==5){   	      
	      hitedens6->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits6->Fill(Radius,(1.));
	      double firstBin = hitedens6->GetBinContent(15);
	      hitedens6->SetBinContent(15,firstBin*3.0*1.2);
	    }
	    if (layer->at(j)==6){   	      
	      hitedens7->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits7->Fill(Radius,(1.));
	      double firstBin = hitedens7->GetBinContent(17);
	      hitedens7->SetBinContent(17,firstBin*2.0*1.1);
	    }
	  }   // end of radius conditional
	}   // end of inner tracker endcap

      //----------------------------------------------------------------
      // -- OTE---------------------------------------------------------

	if (subdet->at(j) == 6){ 
	  if (Radius < r && Radius > rinn ) {
	    if (layer->at(j)==0){   	      
	      hitedens8->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits8->Fill(Radius,(1.));
	      double firstBin = hitedens8->GetBinContent(36);
	      hitedens8->SetBinContent(36,firstBin*10.0*1.1);
	    }
	    if (layer->at(j)==1){   	      
	      hitedens9->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits9->Fill(Radius,(1.));
	      double firstBin = hitedens9->GetBinContent(36);
	      hitedens9->SetBinContent(36,firstBin*10.0*1.1);
	    }
	    if (layer->at(j)==2){   	      
	      hitedens10->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits10->Fill(Radius,(1.));
	      double firstBin = hitedens10->GetBinContent(36);
	      hitedens10->SetBinContent(36,firstBin*10.0*1.1);	      
	    }
	    if (layer->at(j)==3){   	      
	      hitedens11->Fill(Radius,1.0/(area*nentries));    // hit density
	      hitehits11->Fill(Radius,(1.));
	      double firstBin = hitedens11->GetBinContent(36);
	      hitedens11->SetBinContent(36,firstBin*10.0*1.1);	      
	    }
	  } // end of radius conditional	  
	} // end of outer tracker endcap
      } // end of loops in segments for tracker endcaps
    }  // end of loop in hits
  }   // end of loop in tree entries

  // Plotting for VXD barrel  
  cvxdb->cd();

  double ErrorsVXDL1[25];
  for (int i = 0 ; i < 25 ; i++){ErrorsVXDL1[i]=0;}  // array initialisation
  int NBins1 = hzvxdhits1->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdhits1->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " bin " << bin << " content " << cont << " error " << error4 << " relative error " << error4<< std::endl ;
    if (cont >  0 ){
      ErrorsVXDL1[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hzvxddens1->GetNbinsX ();
  for (int bin = 1 ; bin < NBins2+1 ; bin++){
    //std::cout << " relative errors " << ErrorsVXDL1[bin-1] << std::endl ;
  }
  //int NBins2 = hzvxddens1->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    //std::cout << " bin2 " << bin2 << std::endl ;
    double cont2 = hzvxddens1->GetBinContent(bin2);  
    //std::cout << " content " << cont2 << std::endl ;
    double relErr = cont2*ErrorsVXDL1[bin2-1];
    //std::cout << " relative error " << relErr << std::endl ;
    hzvxddens1->SetBinError(bin2, relErr);
  }


  double ErrorsVXDL2[25];
  for (int i = 0 ; i < 25 ; i++){ErrorsVXDL2[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdhits2->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " bin " << bin << " content " << cont << " error " << sqrt(cont) << " relative error " << error4<< std::endl ;
    if (cont >  0 ){
      ErrorsVXDL2[bin-1] = error4/cont ;
    }
  }
  for (int bin = 1 ; bin < NBins2+1 ; bin++){
    //std::cout << " relative errors " << ErrorsVXDL2[bin-1] << std::endl ;
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    //std::cout << " bin2 " << bin2 << std::endl ;
    double cont2 = hzvxddens2->GetBinContent(bin2);  
    //std::cout << " content " << cont2 << std::endl ;
    double relErr = cont2*ErrorsVXDL2[bin2-1];
    //std::cout << " relative error " << relErr << std::endl ;
    hzvxddens2->SetBinError(bin2, relErr);
  }


  double ErrorsVXDL3[25];
  for (int i = 0 ; i < 25 ; i++){ErrorsVXDL3[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdhits3->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " bin " << bin << " content " << cont << " error " << sqrt(cont) << " relative error " << error4<< std::endl ;
    if (cont >  0 ){
      ErrorsVXDL3[bin-1] = error4/cont ;
    }
  }
  for (int bin = 1 ; bin < NBins2+1 ; bin++){
    //std::cout << " relative errors " << ErrorsVXDL3[bin-1] << std::endl ;
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    //std::cout << " bin2 " << bin2 << std::endl ;
    double cont2 = hzvxddens3->GetBinContent(bin2);  
    //std::cout << " content " << cont2 << std::endl ;
    double relErr = cont2*ErrorsVXDL3[bin2-1];
    //std::cout << " relative error " << relErr << std::endl ;
    hzvxddens3->SetBinError(bin2, relErr);
  }
  

  double ErrorsVXDL4[25];
  for (int i = 0 ; i < 25 ; i++){ErrorsVXDL4[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdhits4->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " bin " << bin << " content " << cont << " error " << sqrt(cont) << " relative error " << error4<< std::endl ;
    if (cont >  0 ){
      ErrorsVXDL4[bin-1] = error4/cont ;
    }
  }
  for (int bin = 1 ; bin < NBins2+1 ; bin++){
    //std::cout << " relative errors " << ErrorsVXDL4[bin-1] << std::endl ;
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    //std::cout << " bin2 " << bin2 << std::endl ;
    double cont2 = hzvxddens4->GetBinContent(bin2);  
    //std::cout << " content " << cont2 << std::endl ;
    double relErr = cont2*ErrorsVXDL4[bin2-1];
    //std::cout << " relative error " << relErr << std::endl ;
    hzvxddens4->SetBinError(bin2, relErr);
  }


  double ErrorsVXDL5[25];
  for (int i = 0 ; i < 25 ; i++){ErrorsVXDL5[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdhits5->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " bin " << bin << " content " << cont << " error " << sqrt(cont) << " relative error " << error4<< std::endl ;
    if (cont >  0 ){
      ErrorsVXDL5[bin-1] = error4/cont ;
    }
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    //std::cout << " bin2 " << bin2 << std::endl ;
    double cont2 = hzvxddens5->GetBinContent(bin2);  
    //std::cout << " content " << cont2 << std::endl ;
    double relErr = cont2*ErrorsVXDL5[bin2-1];
    //std::cout << " relative error " << relErr << std::endl ;
    hzvxddens5->SetBinError(bin2, relErr);
  }


  double ErrorsVXDL6[25];
  for (int i = 0 ; i < 25 ; i++){ErrorsVXDL6[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdhits6->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " bin " << bin << " content " << cont << " error " << sqrt(cont) << " relative error " << error4<< std::endl ;
    if (cont >  0 ){
      ErrorsVXDL6[bin-1] = error4/cont ;
    }
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    //std::cout << " bin2 " << bin2 << std::endl ;
    double cont2 = hzvxddens6->GetBinContent(bin2);  
    //std::cout << " content " << cont2 << std::endl ;
    double relErr = cont2*ErrorsVXDL6[bin2-1];
    //std::cout << " relative error " << relErr << std::endl ;
    hzvxddens6->SetBinError(bin2, relErr);
  }

  
  hzvxddens1->Draw();
  //hzvxddens1->SetMaximum(0.45);  
  hzvxddens2->Draw("same");
  hzvxddens4->Draw("same");
  hzvxddens3->Draw("same");
  hzvxddens5->Draw("same");
  hzvxddens6->Draw("same");
  
  TLegend *   leg = new TLegend(0.2,0.36,0.55,0.68);
  leg->AddEntry(hzvxddens1,"VXD L1","p");
  leg->AddEntry(hzvxddens2,"VXD L2","p");
  leg->AddEntry(hzvxddens3,"VXD L3","p");
  leg->AddEntry(hzvxddens4,"VXD L4","p");
  leg->AddEntry(hzvxddens5,"VXD L5","p");
  leg->AddEntry(hzvxddens6,"VXD L6","p");
  leg->Draw();
  TLegend *   leg4 = new TLegend(0.2,0.36,0.55,0.68);
  //leg4->AddEntry( hzvxddens5,"FCCee 365 GeV","");
  //leg4->Draw();




  // calculation of relative errors for barrel tracker, and plotting of the histograms
  ctb->cd();
  double ErrorsTBL1[50];
  for (int i = 0 ; i < 50 ; i++){ErrorsTBL1[i]=0;}  // array initialisation
  int NBins1 = hztbhits1->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hztbhits1->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTBL1[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hztbdens1->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hztbdens1->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTBL1[bin2-1];
    hztbdens1->SetBinError(bin2, relErr);
  }

  double ErrorsTBL2[50];
  for (int i = 0 ; i < 50 ; i++){ErrorsTBL2[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hztbhits2->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTBL2[bin-1] = error4/cont ;
    }
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hztbdens2->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTBL2[bin2-1];
    hztbdens2->SetBinError(bin2, relErr);
  }

  double ErrorsTBL3[50];
  for (int i = 0 ; i < 50 ; i++){ErrorsTBL3[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hztbhits3->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTBL3[bin-1] = error4/cont ;
    }
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hztbdens3->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTBL3[bin2-1];
    hztbdens3->SetBinError(bin2, relErr);
  }

  double ErrorsTBL4[50];
  for (int i = 0 ; i < 50 ; i++){ErrorsTBL4[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hztbhits4->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTBL4[bin-1] = error4/cont ;
    }
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hztbdens4->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTBL4[bin2-1];
    hztbdens4->SetBinError(bin2, relErr);
  }

  double ErrorsTBL5[50];
  for (int i = 0 ; i < 50 ; i++){ErrorsTBL5[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hztbhits5->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTBL5[bin-1] = error4/cont ;
    }
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hztbdens5->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTBL5[bin2-1];
    hztbdens5->SetBinError(bin2, relErr);
  }

  double ErrorsTBL6[50];
  for (int i = 0 ; i < 50 ; i++){ErrorsTBL6[i]=0;}  // array initialisation
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hztbhits6->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTBL6[bin-1] = error4/cont ;
    }
  }
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hztbdens6->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTBL6[bin2-1];
    hztbdens6->SetBinError(bin2, relErr);
  }

  
  hztbdens1->Draw();
  
  hztbdens2->Draw("same");
  hztbdens4->Draw("same");
  hztbdens3->Draw("same");
  hztbdens5->Draw("same");
  hztbdens6->Draw("same");
  
  TLegend *   leg2 = new TLegend(0.2,0.36,0.55,0.68);
  leg2->AddEntry(hztbdens1,"ITB L1","p");
  leg2->AddEntry(hztbdens2,"ITB L2","p");
  leg2->AddEntry(hztbdens3,"ITB L3","p");
  leg2->AddEntry(hztbdens4,"OTB L1","p");
  leg2->AddEntry(hztbdens5,"OTB L2","p");
  leg2->AddEntry(hztbdens6,"OTB L3","p");
  leg2->Draw();
  //TLegend *   leg44 = new TLegend(0.2,0.36,0.55,0.68);
  //leg44->AddEntry( hztbdens5,"FCCee 365GeV","");
  //leg4->Draw();




  cvxdec->cd(0);

  double ErrorsVXDE6[55];
  for (int i = 0 ; i < 55 ; i++){ErrorsVXDE6[i]=0;}  // array initialisation
  int NBins1 = hzvxdECHits6->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdECHits6->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " D6 : bin " << bin << " no of hits " << cont << " poissonian error " << error4 << std::endl ;
    if (cont >  0 ){
      //std::cout << " do I enter here ? " << std::endl ;
      ErrorsVXDE6[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hzvxdECdens6->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont = hzvxdECHits6->GetBinContent(bin2);
    double error4 = sqrt(cont);
    double cont2 = hzvxdECdens6->GetBinContent(bin2);  
    //std::cout << " relative hit error " << ErrorsVXDE6[bin2-1] << std::endl ;
    double relErr = cont2*ErrorsVXDE6[bin2-1];
    //std::cout << " D6 : bin " << bin2 << " content " << cont2 << " no of hits " << cont << " poissonian error " << error4 << " rel. error " << relErr << std::endl ;
    hzvxdECdens6->SetBinError(bin2, relErr);
  }

  double ErrorsVXDE2[55];
  for (int i = 0 ; i < 55 ; i++){ErrorsVXDE2[i]=0;}  // array initialisation
  int NBins1 = hzvxdECHits2->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdECHits2->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsVXDE2[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hzvxdECdens2->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hzvxdECdens2->GetBinContent(bin2);  
    double relErr = cont2*ErrorsVXDE2[bin2-1];
    hzvxdECdens2->SetBinError(bin2, relErr);
  }

  double ErrorsVXDE3[55];
  for (int i = 0 ; i < 55 ; i++){ErrorsVXDE3[i]=0;}  // array initialisation
  int NBins1 = hzvxdECHits3->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdECHits3->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsVXDE3[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hzvxdECdens3->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hzvxdECdens3->GetBinContent(bin2);  
    double relErr = cont2*ErrorsVXDE3[bin2-1];
    hzvxdECdens3->SetBinError(bin2, relErr);
    std::cout << " VXD D3 : bin " << bin2 << " content " << cont2 << " Error " << relErr << std::endl ;
  }

  double ErrorsVXDE1[55];
  for (int i = 0 ; i < 55 ; i++){ErrorsVXDE1[i]=0;}  // array initialisation
  int NBins1 = hzvxdECHits1->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdECHits1->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsVXDE1[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hzvxdECdens1->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hzvxdECdens1->GetBinContent(bin2);  
    double relErr = cont2*ErrorsVXDE1[bin2-1];
    hzvxdECdens1->SetBinError(bin2, relErr);
  }

  double ErrorsVXDE5[55];
  for (int i = 0 ; i < 55 ; i++){ErrorsVXDE5[i]=0;}  // array initialisation
  int NBins1 = hzvxdECHits5->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdECHits5->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsVXDE5[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hzvxdECdens5->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hzvxdECdens5->GetBinContent(bin2);  
    double relErr = cont2*ErrorsVXDE5[bin2-1];
    hzvxdECdens5->SetBinError(bin2, relErr);
    //std::cout << " D5 : bin " << bin2 << " content " << cont2 << " rel. error " << relErr << std::endl ;
  }

  double ErrorsVXDE4[55];
  for (int i = 0 ; i < 55 ; i++){ErrorsVXDE4[i]=0;}  // array initialisation
  int NBins1 = hzvxdECHits4->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hzvxdECHits4->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsVXDE4[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hzvxdECdens4->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hzvxdECdens4->GetBinContent(bin2);  
    double relErr = cont2*ErrorsVXDE4[bin2-1];
    hzvxdECdens4->SetBinError(bin2, relErr);
  }

  hzvxdECdens1->Draw();  
  hzvxdECdens1->SetLineColor(2);
  hzvxdECdens1->SetMarkerColor(2);
  hzvxdECdens2->Draw("same");
  hzvxdECdens2->SetLineColor(3);
  hzvxdECdens2->SetMarkerColor(3);
  hzvxdECdens3->Draw("same");
  hzvxdECdens3->SetLineColor(4);
  hzvxdECdens3->SetMarkerColor(4);
  hzvxdECdens4->Draw("same");
  hzvxdECdens4->SetLineColor(5);
  hzvxdECdens4->SetMarkerColor(5);
  hzvxdECdens5->Draw("same");
  hzvxdECdens5->SetLineColor(6);
  hzvxdECdens5->SetMarkerColor(6);
  hzvxdECdens6->Draw("same");
  hzvxdECdens6->SetLineColor(7);
  hzvxdECdens6->SetMarkerColor(7);
  
  TLegend *   leg3 = new TLegend(0.2,0.36,0.55,0.68);
  leg3->AddEntry(hzvxdECdens1,"VXDE D1","p");
  leg3->AddEntry(hzvxdECdens2,"VXDE D2","p");
  leg3->AddEntry(hzvxdECdens3,"VXDE D3","p");
  leg3->AddEntry(hzvxdECdens4,"VXDE D4","p");
  leg3->AddEntry(hzvxdECdens5,"VXDE D5","p");
  leg3->AddEntry(hzvxdECdens6,"VXDE D6","p");
  leg3->Draw();
  //leg4->Draw();

  // Tracker endcaps
  cte->cd();

  double ErrorsTE6[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE6[i]=0;}  // array initialisation
  int NBins1 = hitehits6->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits6->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " D6 : bin " << bin << " no of hits " << cont << " poissonian error " << error4 << std::endl ;
    if (cont >  0 ){
      //std::cout << " do I enter here ? " << std::endl ;
      ErrorsTE6[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens6->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont = hitehits6->GetBinContent(bin2);
    double error4 = sqrt(cont);
    double cont2 = hitedens6->GetBinContent(bin2);  
    //std::cout << " relative hit error " << ErrorsTE6[bin2-1] << std::endl ;
    double relErr = cont2*ErrorsTE6[bin2-1];
    std::cout << " D6 : bin " << bin2 << " content " << cont2 << " no of hits " << cont << " poissonian error " << error4 << " rel. error " << relErr << std::endl ;
    hitedens6->SetBinError(bin2, relErr);
  }

  double ErrorsTE2[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE2[i]=0;}  // array initialisation
  int NBins1 = hitehits2->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits2->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE2[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens2->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens2->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE2[bin2-1];
    hitedens2->SetBinError(bin2, relErr);
  }

  double ErrorsTE3[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE3[i]=0;}  // array initialisation
  int NBins1 = hitehits3->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits3->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE3[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens3->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens3->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE3[bin2-1];
    hitedens3->SetBinError(bin2, relErr);
  }

  double ErrorsTE1[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE1[i]=0;}  // array initialisation
  int NBins1 = hitehits1->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits1->GetBinContent(bin);
    //std::cout << " bin " << bin << " hits " <<  cont << std::endl ;
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE1[bin-1] = error4/cont ;
      std::cout << " index " << bin-1 << " error " <<  error4/cont << std::endl ;
    }
  }
  int NBins2 = hitedens1->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens1->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE1[bin2-1];
    //std::cout << " D1 : bin " << bin2 << " content " << cont2  << std::endl ;
    //std::cout << " D1 : bin " << bin2 << " content " << cont2 << " no of hits " << cont << " poissonian error " << error4 << " rel. error " << relErr << std::endl ;
    hitedens1->SetBinError(bin2, relErr);
  }

  double ErrorsTE5[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE5[i]=0;}  // array initialisation
  int NBins1 = hitehits5->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits5->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE5[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens5->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens5->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE5[bin2-1];
    hitedens5->SetBinError(bin2, relErr);
    //std::cout << " D5 : bin " << bin2 << " content " << cont2 << " rel. error " << relErr << std::endl ;
  }

  double ErrorsTE4[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE4[i]=0;}  // array initialisation
  int NBins1 = hitehits4->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits4->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE4[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens4->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens4->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE4[bin2-1];
    hitedens4->SetBinError(bin2, relErr);
  }

  double ErrorsTE7[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE7[i]=0;}  // array initialisation
  int NBins1 = hitehits7->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits7->GetBinContent(bin);
    double error4 = sqrt(cont);
    //std::cout << " D6 : bin " << bin << " no of hits " << cont << " poissonian error " << error4 << std::endl ;
    if (cont >  0 ){
      //std::cout << " do I enter here ? " << std::endl ;
      ErrorsTE7[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens7->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont = hitehits7->GetBinContent(bin2);
    double error4 = sqrt(cont);
    double cont2 = hitedens7->GetBinContent(bin2);  
    //std::cout << " relative hit error " << ErrorsTE6[bin2-1] << std::endl ;
    double relErr = cont2*ErrorsTE7[bin2-1];
    //std::cout << " D6 : bin " << bin2 << " content " << cont2 << " no of hits " << cont << " poissonian error " << error4 << " rel. error " << relErr << std::endl ;
    hitedens6->SetBinError(bin2, relErr);
  }

  double ErrorsTE8[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE8[i]=0;}  // array initialisation
  int NBins1 = hitehits8->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits8->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE8[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens8->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens8->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE8[bin2-1];
    hitedens8->SetBinError(bin2, relErr);
  }

  double ErrorsTE9[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE9[i]=0;}  // array initialisation
  int NBins1 = hitehits9->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits9->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE9[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens9->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens9->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE9[bin2-1];
    hitedens9->SetBinError(bin2, relErr);
  }

  double ErrorsTE10[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE10[i]=0;}  // array initialisation
  int NBins1 = hitehits10->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits10->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE10[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens10->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens10->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE10[bin2-1];
    hitedens10->SetBinError(bin2, relErr);
  }

  double ErrorsTE11[110];
  for (int i = 0 ; i < 110 ; i++){ErrorsTE11[i]=0;}  // array initialisation
  int NBins1 = hitehits11->GetNbinsX ();
  for (int bin = 1 ; bin < NBins1+1 ; bin++){
    double cont = hitehits11->GetBinContent(bin);
    double error4 = sqrt(cont);
    if (cont >  0 ){
      ErrorsTE11[bin-1] = error4/cont ;
    }
  }
  int NBins2 = hitedens11->GetNbinsX ();
  for (int bin2 = 1 ; bin2 < NBins2+1 ; bin2++){
    double cont2 = hitedens11->GetBinContent(bin2);  
    double relErr = cont2*ErrorsTE11[bin2-1];
    hitedens11->SetBinError(bin2, relErr);
    //std::cout << " D5 : bin " << bin2 << " content " << cont2 << " rel. error " << relErr << std::endl ;
  }

  hitedens1->Draw();  
  hitedens2->Draw("same");
  hitedens3->Draw("same");
  hitedens4->Draw("same");
  hitedens5->Draw("same");
  hitedens6->Draw("same");
  hitedens7->Draw("same");  
  hitedens8->Draw("same");
  hitedens9->Draw("same");
  hitedens10->Draw("same");
  hitedens11->Draw("same");
  
  TLegend *   leg5 = new TLegend(0.2,0.36,0.55,0.68);
  leg5->AddEntry(hitedens1,"ITE D1","p");
  leg5->AddEntry(hitedens2,"ITE D2","p");
  leg5->AddEntry(hitedens3,"ITE D3","p");
  leg5->AddEntry(hitedens4,"ITE D4","p");
  leg5->AddEntry(hitedens5,"ITE D5","p");
  leg5->AddEntry(hitedens6,"ITE D6","p");
  leg5->AddEntry(hitedens7,"ITE D7","p");
  leg5->AddEntry(hitedens8,"OTE D1","p");
  leg5->AddEntry(hitedens9,"OTE D2","p");
  leg5->AddEntry(hitedens10,"OTE D3","p");
  leg5->AddEntry(hitedens11,"OTE D4","p");
  leg5->Draw();
  //leg4->Draw();

  VXDBrad[0]=testcounter1;
  VXDBrad[1]=testcounter2;
  VXDBrad[2]=testcounter3;
  VXDBrad[3]=testcounter4;
  VXDBrad[4]=testcounter5;
  VXDBrad[5]=testcounter6;
  VXDBrad_errors[0]=sqrt(testcounter1);
  VXDBrad_errors[1]=sqrt(testcounter2);
  VXDBrad_errors[2]=sqrt(testcounter3);
  VXDBrad_errors[3]=sqrt(testcounter4);
  VXDBrad_errors[4]=sqrt(testcounter5);
  VXDBrad_errors[5]=sqrt(testcounter6);

  for (int ii=0;ii<6;ii++){
    VXDBrad_wgt[ii] = VXDBrad[ii]/(nentries*VXDLayers_area[ii]);
    VXDBradErrors_wgt[ii] = VXDBrad_errors[ii]/(nentries*VXDLayers_area[ii]);
    std::cout << " layer " << ii << " hits " << VXDBrad[ii] << " / " << nentries << " x " << VXDLayers_area[ii] << std::endl ;
  }

  //std::cout << " test counter " << testcounter << std::endl ;

  c5->cd();
  TGraphErrors *VXDBarrel_rad = new TGraphErrors(6,VXDLayers_radii,VXDBrad_wgt,zeros,VXDBradErrors_wgt);
  VXDBarrel_rad -> GetXaxis() -> SetTitle("R (mm)");
  VXDBarrel_rad -> GetYaxis() -> SetTitle("hits / mm^{2} / BX");
  //VXDBarrel_rad -> SetMinimum(0);
  VXDBarrel_rad->GetXaxis()->SetLimits(0.,70.);
  VXDBarrel_rad->Draw("AP");  


  ctest->cd(1);
  hzvxdECHits1->Draw();
  ctest->cd(2);

}
