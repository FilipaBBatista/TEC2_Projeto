void energia_total() {


Double_t detector0;
Double_t detector1;
Double_t detector2;
Double_t detector3;
Double_t Soma;

TFile *file = new TFile("AmberTarget_Run_0.root","READ");
TFile *ficheiroGravar = new TFile("energia_total.root","RECREATE");
TTree *dados = (TTree*) file->Get("edep_Per_Event");


dados->SetBranchAddress("detector0",&detector0);
dados->SetBranchAddress("detector1",&detector1);
dados->SetBranchAddress("detector2",&detector2);
dados->SetBranchAddress("detector3",&detector3);
TTree *newTree = new TTree("Soma", "Soma de energias");
newTree->Branch("Soma",&Soma, "Soma/D");

Long64_t Nentries = dados->GetEntries();
for (int i = 0; i < Nentries; i++){
	dados->GetEntry(i);
	Soma = detector0 + detector1 + detector2 + detector3;
	newTree->Fill();
	}
	
newTree->Write();
}




