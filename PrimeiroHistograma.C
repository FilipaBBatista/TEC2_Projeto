void PrimeiroHistograma(){

//ler ficheiro
TFile *ficheiro = new TFile("AmberTarget_Run_0.root", "READ");
//criar ficheiro
TFile *ficheiroGravar = new TFile("Analise.root", "RECREATE");
//buscar a arvore certa
TTree *dados = (TTree*)ficheiro->Get("edep_Per_Event");


Int_t nBins=500;
Double_t minBin=0.0;
Double_t maxBin=400000;

//criar o nosso histograma
TH1D* histoDetetor=new
TH1D ("histoDetetor","histoDetetor",nBins,minBin,maxBin);

dados->Draw("detector0>>histoDetetor","detector0>0");

histoDetetor->SetTitle("TECII");
histoDetetor->Write();
}
