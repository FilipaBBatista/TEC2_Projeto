void energia_particula(){

//ler ficheiro
TFile *ficheiro = new TFile("AmberTarget_Run_0.root", "READ");
//criar ficheiro
TFile *ficheiroGravar = new TFile("Histogramas.root", "RECREATE");
//buscar a arvore certa
TTree *dados = (TTree*)ficheiro->Get("tracksData");


Int_t nBins=500;
Double_t minBin=0.0;
Double_t maxBin=100000;

Int_t nHistos=4;

THStack *hs = new THStack("hs","");
TH1F* histoDetetor[nHistos];
TCanvas *canvas;
TString branchName;

canvas =new TCanvas("canvas","energia particula",10,10,700,900);

for (Int_t i=0;i<nHistos;i++){
	TString histoName="EdepDet"+TString::Itoa(i,10)+"_keV";
	histoDetetor[i]=new TH1F (histoName,histoName,nBins,minBin,maxBin);
	branchName="EdepDet"+TString::Itoa(i,10)+"_keV";
	dados->Draw(branchName+">>"+histoName, "particlePDG ==13 || particlePDG == -13", branchName+">0" );
	histoDetetor[i]->SetLineColor(i+1);
	histoDetetor[i]->SetTitle(histoName);
	hs->Add(histoDetetor[i]);
	histoDetetor[i]->Write();
	}
	
hs->Draw("noStack");
canvas->BuildLegend();
}
