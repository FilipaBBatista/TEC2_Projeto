void primeiroHistograma(){

TFile *f = new TFile("AmberTarget_Run_0.root","READ");
TFile *fsave = new TFile("histograma.root","RECREATE");
TTree *dados = (TTree*)f->Get("edep_Per_Event");
Int_t nBins=500;
Double_t minBin=0;
Double_t maxBin=400000;
TH1D *histoDetetor = new TH1D("histoDetetor","histoDetetor",nBins,minBin,maxBin);


dados->Draw("detector0>>histoDetetor","detector0>0");

histoDetetor->Write();
}
