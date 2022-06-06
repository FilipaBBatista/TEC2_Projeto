void energia_total() {


Double_t detector_0;
Double_t detector_1;
Double_t detector_2;
Double_t detector_3;
Double_t soma;

TFile *file = new TFile("AmberTarget_Run_0.root","READ");
TFile *ficheiroGravar = new TFile("energia_total.root","RECREATE");

TTree *dados = (TTree*) file->Get("edep_Per_Event");
dados->SetBranchAddress("detector0",&detector_0);
dados->SetBranchAddress("detector1",&detector_1);
dados->SetBranchAddress("detector2",&detector_2);
dados->SetBranchAddress("detector3",&detector_3);
TTree *newTree = new TTree("Soma","Soma de energias");
newTree->Branch("Soma",&soma,"Soma/D");
Long64_t Nentries = dados->GetEntries();

for (int i = 0; i < Nentries; i++){
	dados->GetEntry(i);
	soma = detector_0 + detector_1 + detector_2 + detector_3;
	newTree->Fill();
	}
newTree->Write();
}
