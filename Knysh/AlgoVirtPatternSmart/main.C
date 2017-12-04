#include "BKHashTable.h"
#include <ctime>
#include <vector>
#include "TGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "BKLinkedHashTable.h"
#include "BKHashFactory.h"
#include "BKSmartFollowing.h"

using namespace BKData;

int main(void)
{
  srand (time(NULL));
  size_t m = 1;
  std::vector<double> timeV;
  std::vector<double> nElements;
  timeV.reserve(10);
  nElements.reserve(10);
  for(size_t iter = 0; iter <= 19; iter++)
  {
    BKHashInterface<int,int>* bkht = BKHashFactory<int,int>::BKNewHash("simple_hash");
    bkht->BKSetSize(5e5);
    clock_t tStart = clock();
    for(size_t cntr = 0; cntr < m; cntr++)
    {
      size_t rKey = rand()%m;
      int rValue = rand()%1000;
      bkht->BKPutValue(rKey,rValue);
    }
    delete bkht;
    m = m*2;
    std::cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s " << std::endl;
    timeV.push_back((double)(clock() - tStart)/CLOCKS_PER_SEC);
    nElements.push_back(log(m));
  }
  
  size_t m2 = 1;
  std::vector<double> timeV2;
  std::vector<double> nElements2;
  timeV2.reserve(10);
  nElements2.reserve(10);
  for(size_t iter = 0; iter <= 19; iter++)
  {
    BKHashInterface<int,int>* bkht2 = BKHashFactory<int,int>::BKNewHash("linked_hash");
    bkht2->BKSetSize(5e5);
    clock_t tStart = clock();
    for(size_t cntr = 0; cntr < m2; cntr++)
    {
      size_t rKey = rand()%m2;
      int rValue = rand()%1000;
      bkht2->BKPutValue(rKey,rValue);
    }
    delete bkht2;
    m2 = m2*2;
    std::cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s " << std::endl;
    timeV2.push_back((double)(clock() - tStart)/CLOCKS_PER_SEC);
    nElements2.push_back(log(m2));
  }
  TCanvas* c1 = new TCanvas();
  TGraph* gr2 = new TGraph(int(timeV2.size()), &nElements2[0], &timeV2[0]);
  TGraph* gr = new TGraph(int(timeV.size()), &nElements[0], &timeV[0]);
  gr->SetMarkerStyle(20);
  gr2->SetMarkerStyle(22);
  gr->SetMarkerColor(kGreen);
  gr2->SetMarkerColor(kRed);
  gr->Draw("AP");
  gr2->Draw("P");
  TLegend* legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("Hash performance"); // option "C" allows to center the header
   legend->AddEntry(gr,"Simple hash","p");
   legend->AddEntry(gr2,"hash+linked list","p");
   legend->Draw();
  c1->SaveAs("HashComplecity.root");
  delete gr2;
  delete legend;
  delete gr;
  delete c1;
  
  return 0;
}
