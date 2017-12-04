void test_00() {
  Int_t counter[] = {2, 3, 28, 409, 5160, 31584, 374402};
  Int_t x[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

  TCanvas *c1 = new TCanvas("Canvas1", "Canvas", 1280, 720);

  TGraph* g1 = new TGraph(7,x,counter);
  g1->SetTitle("Quicksort");
  g1->GetXaxis()->SetTitle("Number of elements");
  g1->GetYaxis()->SetTitle("Time");
  g1->SetMarkerStyle(kFullCircle);
  g1->SetMarkerColor(kRed);
  g1->SetLineColor(kRed);
  g1->SetLineWidth(5);
  g1->SetMarkerSize(2);

  g1->Draw("ACP");
  c1->SaveAs("spectr.png");
  //c1->Close();
}
