void plot_obj()
{
  TString roostr = "";

  //////////////////////////////////////

  TFile *input = new TFile("out.root", "read");

  TTree *tree = (TTree*)input->Get("tree_out");

  //////
  roostr = "canv_top_beforeCorr";
  TCanvas *canv_top_beforeCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_top_beforeCorr->SetRightMargin(0.15);
  tree->Draw("y_pA:x_pA >>h_top_before(30, 140, 260, 55, 210, 240)", "", "colz");
  
  roostr = "canv_top_afterCorr";
  TCanvas *canv_top_afterCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_top_afterCorr->SetRightMargin(0.15);
  tree->Draw("y_pA+corrY_pA : x_pA-corrX_pA >>h_top_after(30, 140, 260, 55, 210, 240)", "", "colz");
  
  //////
  roostr = "canv_bot_beforeCorr";
  TCanvas *canv_bot_beforeCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_bot_beforeCorr->SetRightMargin(0.15);
  tree->Draw("y_pA:x_pA >>h_bot_before(80, 50, 260, 20, 0, 20)", "", "colz");
  
  roostr = "canv_bot_afterCorr";
  TCanvas *canv_bot_afterCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_bot_afterCorr->SetRightMargin(0.15);
  tree->Draw("y_pA+corrY_pA : x_pA-corrX_pA >>h_bot_after(80, 50, 260, 20, 0, 20)", "", "colz");
  
  //////
  roostr = "canv_up_beforeCorr";
  TCanvas *canv_up_beforeCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_up_beforeCorr->SetRightMargin(0.15);
  tree->Draw("x_pA:z_pA >>h_up_before(20, 0, 20, 130, 0, 260)", "", "colz");
  
  roostr = "canv_up_afterCorr";
  TCanvas *canv_up_afterCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_up_afterCorr->SetRightMargin(0.15);
  tree->Draw("x_pA-corrX_pA:z_pA+corrY_pA >>h_up_after(20, 0, 20, 130, 0, 260)", "", "colz");
  
  //////
  roostr = "canv_down_beforeCorr";
  TCanvas *canv_down_beforeCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_down_beforeCorr->SetRightMargin(0.15);
  tree->Draw("x_pA:z_pA >>h_down_before(20, 1020, 1038, 130, 0, 260)", "", "colz");
  
  roostr = "canv_down_afterCorr";
  TCanvas *canv_down_afterCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_down_afterCorr->SetRightMargin(0.15);
  tree->Draw("x_pA-corrX_pA:z_pA+corrY_pA >>h_down_after(20, 1020, 1038, 130, 0, 260)", "", "colz");
  
  //////
  roostr = "canv_gh_down_beforeCorr";
  TCanvas *canv_gh_down_beforeCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_gh_down_beforeCorr->SetRightMargin(0.15);

  int n_gh_down_before = tree->Draw("x_pA:z_pA", "", "goff");
  TGraph *gh_down_before = new TGraph(n_gh_down_before, tree->GetV2(), tree->GetV1() );
  gh_down_before->Draw("ap");
  gh_down_before->SetMarkerColor(kBlack);
  gh_down_before->SetMarkerStyle(7);
  
  int n_gh_down_after = tree->Draw("x_pA-corrX_pA:z_pA+corrY_pA", "", "goff");
  TGraph *gh_down_after = new TGraph(n_gh_down_after, tree->GetV2(), tree->GetV1() );
  gh_down_after->Draw("same p");
  gh_down_after->SetMarkerColor(kRed);
  gh_down_after->SetMarkerStyle(7);
 
  //////
  roostr = "canv_gh_top_beforeCorr";
  TCanvas *canv_gh_top_beforeCorr = new TCanvas(roostr, roostr, 900, 650);
  canv_gh_top_beforeCorr->SetRightMargin(0.15);

  int n_gh_top_before = tree->Draw("y_pA:x_pA", "", "goff");
  TGraph *gh_top_before = new TGraph(n_gh_top_before, tree->GetV2(), tree->GetV1() );
  gh_top_before->Draw("ap");
  gh_top_before->SetMarkerColor(kBlack);
  gh_top_before->SetMarkerStyle(7);
  
  int n_gh_top_after = tree->Draw("y_pA+corrY_pA : x_pA-corrX_pA", "", "goff");
  TGraph *gh_top_after = new TGraph(n_gh_top_after, tree->GetV2(), tree->GetV1() );
  gh_top_after->Draw("same p");
  gh_top_after->SetMarkerColor(kRed);
  gh_top_after->SetMarkerStyle(7);
 
}

