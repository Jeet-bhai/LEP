    void ratiop(TCanvas *d, int i, TH1* a, TH1* b, TH1 *c){
    d->cd(i);
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
      pad1->SetBottomMargin(0); // Upper and lower plot are joined
      pad1->SetGridx();         // Vertical grid
      pad1->Draw();             // Draw the upper pad: pad1
      pad1->cd(); // pad1 becomes the current pad
  //  pad1->SetLogy();
  //  gPad->SetLogy();
  //a
       a->Draw();               // Draw h1
       b->Draw("same");c->Draw("same");
       TLegend *legend66666 = new TLegend(0.67,0.7,0.89,0.88);
       legend66666->AddEntry(a,"rec","l");
       legend66666->AddEntry(b,"gen","l");
       legend66666->AddEntry(c,"data","l");
       legend66666->Draw();
    // lower plot will be in pad
       d->cd(i);          // Go back to the main canvas before defining pad2
       TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
       pad2->SetTopMargin(0);
       pad2->SetBottomMargin(0.1);
       pad2->SetGridx(); // vertical grid
       pad2->Draw();
       pad2->cd();       // pad2 becomes the current pad
//    pad2->SetLogy();
    
    // Define the ratio plot
    TH1F *h13p = (TH1F*)a->Clone("h13p");
    TH1F *h13pp = (TH1F*)c->Clone("h13pp");
    TH1F *h13ppp = (TH1F*)c->Clone("h13ppp");
        
    h13p->SetLineColor(kBlack);
    h13p->SetMinimum(0);  // Define Y ..
    h13p->SetMaximum(1.6); // .. range
    h13p->Sumw2();
    h13p->SetStats(0);      // No statistics on lower plot
    h13p->Divide(b);
    h13p->SetMarkerStyle(1);
    h13p->SetMarkerSize(1);
    h13p->SetMarkerColor(kBlack);
    h13p->GetXaxis()->SetLabelSize(0.12);
    h13p->GetYaxis()->SetLabelSize(0.12);
    h13p->Draw();       // Draw the ratio plot
        
       
    
    // Define the ratio plot
   // TH1F *h13pp = (TH1F*)c->Clone("h13pp");
    h13pp->SetLineColor(kOrange);
    h13pp->SetMinimum(0);  // Define Y ..
    h13pp->SetMaximum(1.6); // .. range
    h13pp->Sumw2();
    h13pp->SetStats(0);      // No statistics on lower plot
    h13pp->Divide(b);
    h13pp->SetMarkerStyle(2);
    h13pp->SetMarkerSize(1);
    h13pp->SetMarkerColor(kOrange);
    h13pp->GetXaxis()->SetLabelSize(0.12);
    h13pp->GetYaxis()->SetLabelSize(0.12);
    h13pp->Draw("same");       // Draw the ratio plot
    
    // Define the ratio plot
    //TH1F *h13ppp = (TH1F*)h13pp->Clone("h13ppp");
    h13ppp->SetLineColor(kPink);
   h13ppp->SetMinimum(0);  // Define Y ..
    h13ppp->SetMaximum(1.6); // .. range
    h13ppp->Sumw2();
    h13ppp->SetStats(0);      // No statistics on lower plot
    h13ppp->Divide(a);
    h13ppp->SetMarkerStyle(3);
   h13ppp->SetMarkerSize(1);
    h13ppp->SetMarkerColor(kPink);
    h13ppp->GetXaxis()->SetLabelSize(0.12);
    h13ppp->GetYaxis()->SetLabelSize(0.12);
    h13ppp->Draw("same");       // Draw the ratio plot
        
        TLegend *legend666660 = new TLegend(0.67,0.5,0.89,0.88);
        legend666660->AddEntry(h13p,"rec/gen","l");
        legend666660->AddEntry(h13pp,"data/gen","l");
        legend666660->AddEntry(h13ppp,"rec/data","l");
        legend666660->Draw();
    
}



void LEP_jeta(int file_num=94){

    //Define Style
    gStyle->SetOptStat(0);
    gStyle->SetPadBorderMode(0);
    gStyle->SetFrameBorderMode(0);
    gStyle->SetFrameLineWidth(2);
    gStyle->SetLabelSize(0.035,"X");
    gStyle->SetLabelSize(0.035,"Y");
    //gStyle->SetLabelOffset(0.01,"X");
    //gStyle->SetLabelOffset(0.01,"Y");
    gStyle->SetTitleXSize(0.04);
    gStyle->SetTitleXOffset(0.9);
    gStyle->SetTitleYSize(0.04);
    gStyle->SetTitleYOffset(0.9);

    //Define histograms


    TH1 *h1a;
    TH1 *h1b;
    TH1 *h1c;
     TH1 *h1d;
    TH1 *h1e;
    TH1 *h1f;
    
    TH1 *h2a;
    TH1 *h2b;
    TH1 *h2c;
    TH1 *h2d;
    TH1 *h2e;
    TH1 *h2f;
    
    TH1 *h3a;
    TH1 *h3b;
    TH1 *h3c;
    TH1 *h3d;
    TH1 *h3e;
    TH1 *h3f;
    
    TH1 *h4;
    TH1 *h4b;
    TH1 *h5;
    TH1 *h5b;
    TH1 *h6_5to10;  TH1 *h6_10to15;  TH1 *h6_15to20;  TH1 *h6_20to25;  TH1 *h6_25to30;  TH1 *h6_30to35;  TH1 *h6_35to40;  TH1 *h6_40to45;  TH1 *h6_45to50;  TH1 *h6_50to55; TH1 *h6_55to60;
    TH1 *h7_5to10;  TH1 *h7_10to15;  TH1 *h7_15to20;  TH1 *h7_20to25;  TH1 *h7_25to30;  TH1 *h7_30to35;  TH1 *h7_35to40;  TH1 *h7_40to45;  TH1 *h7_45to50;  TH1 *h7_50to55; TH1 *h7_55to60;
    TH1 *h8_5to10;  TH1 *h8_10to15;  TH1 *h8_15to20;  TH1 *h8_20to25;  TH1 *h8_25to30;  TH1 *h8_30to35;  TH1 *h8_35to40;  TH1 *h8_40to45;  TH1 *h8_45to50;  TH1 *h8_50to55; TH1 *h8_55to60;
    
    TH1 *h6b_5to10;  TH1 *h6b_10to15;  TH1 *h6b_15to20;  TH1 *h6b_20to25;  TH1 *h6b_25to30;  TH1 *h6b_30to35;  TH1 *h6b_35to40;  TH1 *h6b_40to45;  TH1 *h6b_45to50;  TH1 *h6b_50to55; TH1 *h6b_55to60;
    TH1 *h7b_5to10;  TH1 *h7b_10to15;  TH1 *h7b_15to20;  TH1 *h7b_20to25;  TH1 *h7b_25to30;  TH1 *h7b_30to35;  TH1 *h7b_35to40;  TH1 *h7b_40to45;  TH1 *h7b_45to50;  TH1 *h7b_50to55; TH1 *h7b_55to60;
    TH1 *h8b_5to10;  TH1 *h8b_10to15;  TH1 *h8b_15to20;  TH1 *h8b_20to25;  TH1 *h8b_25to30;  TH1 *h8b_30to35;  TH1 *h8b_35to40;  TH1 *h8b_40to45;  TH1 *h8b_45to50;  TH1 *h8b_50to55; TH1 *h8b_55to60;
    
    
    TH2 *h9;
    TH2 *h9b;
    TH2 *h10;
    TH2 *h10b;
    TH2 *h11;
    TH2 *h11b;
    
    TH1 *h12_5to10;  TH1 *h12_10to15;  TH1 *h12_15to20;  TH1 *h12_20to25;  TH1 *h12_25to30;  TH1 *h12_30to35;  TH1 *h12_35to40;  TH1 *h12_40to45;  TH1 *h12_45to50;  TH1 *h12_50to55; TH1 *h12_55to60;
    TH1 *h12b_5to10; TH1 *h12b_10to15; TH1 *h12b_15to20; TH1 *h12b_20to25; TH1 *h12b_25to30; TH1 *h12b_30to35; TH1 *h12b_35to40; TH1 *h12b_40to45; TH1 *h12b_45to50; TH1 *h12b_50to55; TH1 *h12b_55to60;
    TH1 *h13_5to10;  TH1 *h13_10to15;  TH1 *h13_15to20;  TH1 *h13_20to25;  TH1 *h13_25to30;  TH1 *h13_30to35;  TH1 *h13_35to40;  TH1 *h13_40to45;  TH1 *h13_45to50;  TH1 *h13_50to55; TH1 *h13_55to60;
    TH1 *h13b_5to10; TH1 *h13b_10to15; TH1 *h13b_15to20; TH1 *h13b_20to25; TH1 *h13b_25to30; TH1 *h13b_30to35; TH1 *h13b_35to40; TH1 *h13b_40to45; TH1 *h13b_45to50; TH1 *h13b_50to55; TH1 *h13b_55to60;
    TH1 *h14_5to10;  TH1 *h14_10to15;  TH1 *h14_15to20;  TH1 *h14_20to25;  TH1 *h14_25to30;  TH1 *h14_30to35;  TH1 *h14_35to40;  TH1 *h14_40to45;  TH1 *h14_45to50;  TH1 *h14_50to55; TH1 *h14_55to60;
    TH1 *h14b_5to10; TH1 *h14b_10to15; TH1 *h14b_15to20; TH1 *h14b_20to25; TH1 *h14b_25to30; TH1 *h14b_30to35; TH1 *h14b_35to40; TH1 *h14b_40to45; TH1 *h14b_45to50; TH1 *h14b_50to55; TH1 *h14b_55to60;
    TH1 *h15_5to10;  TH1 *h15_10to15;  TH1 *h15_15to20;  TH1 *h15_20to25;  TH1 *h15_25to30;  TH1 *h15_30to35;  TH1 *h15_35to40;  TH1 *h15_40to45;  TH1 *h15_45to50;  TH1 *h15_50to55; TH1 *h15_55to60;
    TH1 *h15b_5to10; TH1 *h15b_10to15; TH1 *h15b_15to20; TH1 *h15b_20to25; TH1 *h15b_25to30; TH1 *h15b_30to35; TH1 *h15b_35to40; TH1 *h15b_40to45; TH1 *h15b_45to50; TH1 *h15b_50to55; TH1 *h15b_55to60;
    TH1 *h16_5to10;  TH1 *h16_10to15;  TH1 *h16_15to20;  TH1 *h16_20to25;  TH1 *h16_25to30;  TH1 *h16_30to35;  TH1 *h16_35to40;  TH1 *h16_40to45;  TH1 *h16_45to50;  TH1 *h16_50to55; TH1 *h16_55to60;
    TH1 *h16b_5to10; TH1 *h16b_10to15; TH1 *h16b_15to20; TH1 *h16b_20to25; TH1 *h16b_25to30; TH1 *h16b_30to35; TH1 *h16b_35to40; TH1 *h16b_40to45; TH1 *h16b_45to50; TH1 *h16b_50to55; TH1 *h16b_55to60;
    TH1 *h17_5to10;  TH1 *h17_10to15;  TH1 *h17_15to20;  TH1 *h17_20to25;  TH1 *h17_25to30;  TH1 *h17_30to35;  TH1 *h17_35to40;  TH1 *h17_40to45;  TH1 *h17_45to50;  TH1 *h17_50to55; TH1 *h17_55to60;
    TH1 *h17b_5to10; TH1 *h17b_10to15; TH1 *h17b_15to20; TH1 *h17b_20to25; TH1 *h17b_25to30; TH1 *h17b_30to35; TH1 *h17b_35to40; TH1 *h17b_40to45; TH1 *h17b_45to50; TH1 *h17b_50to55; TH1 *h17b_55to60;
    
    TH2 *h1z_5to10;  TH2 *h1z_10to15;  TH2 *h1z_15to20;  TH2 *h1z_20to25;  TH2 *h1z_25to30;  TH2 *h1z_30to35;  TH2 *h1z_35to40;  TH2 *h1z_40to45;  TH2 *h1z_45to50;  TH2 *h1z_50to55; TH2 *h1z_55to60;
    TH2 *h2z_5to10;  TH2 *h2z_10to15;  TH2 *h2z_15to20;  TH2 *h2z_20to25;  TH2 *h2z_25to30;  TH2 *h2z_30to35;  TH2 *h2z_35to40;  TH2 *h2z_40to45;  TH2 *h2z_45to50;  TH2 *h2z_50to55; TH2 *h2z_55to60;
    TH2 *h3z_5to10;  TH2 *h3z_10to15;  TH2 *h3z_15to20;  TH2 *h3z_20to25;  TH2 *h3z_25to30;  TH2 *h3z_30to35;  TH2 *h3z_35to40;  TH2 *h3z_40to45;  TH2 *h3z_45to50;  TH2 *h3z_50to55; TH2 *h3z_55to60;
    
    TH2 *h1zg_5to10;  TH2 *h1zg_10to15;  TH2 *h1zg_15to20;  TH2 *h1zg_20to25;  TH2 *h1zg_25to30;  TH2 *h1zg_30to35;  TH2 *h1zg_35to40;  TH2 *h1zg_40to45;  TH2 *h1zg_45to50;  TH2 *h1zg_50to55; TH2 *h1zg_55to60;
    TH2 *h2zg_5to10;  TH2 *h2zg_10to15;  TH2 *h2zg_15to20;  TH2 *h2zg_20to25;  TH2 *h2zg_25to30;  TH2 *h2zg_30to35;  TH2 *h2zg_35to40;  TH2 *h2zg_40to45;  TH2 *h2zg_45to50;  TH2 *h2zg_50to55; TH2 *h2zg_55to60;
    TH2 *h3zg_5to10;  TH2 *h3zg_10to15;  TH2 *h3zg_15to20;  TH2 *h3zg_20to25;  TH2 *h3zg_25to30;  TH2 *h3zg_30to35;  TH2 *h3zg_35to40;  TH2 *h3zg_40to45;  TH2 *h3zg_45to50;  TH2 *h3zg_50to55; TH2 *h3zg_55to60;
    
    TH2 *h1zw_5to10;  TH2 *h1zw_10to15;  TH2 *h1zw_15to20;  TH2 *h1zw_20to25;  TH2 *h1zw_25to30;  TH2 *h1zw_30to35;  TH2 *h1zw_35to40;  TH2 *h1zw_40to45;  TH2 *h1zw_45to50;  TH2 *h1zw_50to55; TH2 *h1zw_55to60;
    TH2 *h2zw_5to10;  TH2 *h2zw_10to15;  TH2 *h2zw_15to20;  TH2 *h2zw_20to25;  TH2 *h2zw_25to30;  TH2 *h2zw_30to35;  TH2 *h2zw_35to40;  TH2 *h2zw_40to45;  TH2 *h2zw_45to50;  TH2 *h2zw_50to55; TH2 *h2zw_55to60;
    TH2 *h3zw_5to10;  TH2 *h3zw_10to15;  TH2 *h3zw_15to20;  TH2 *h3zw_20to25;  TH2 *h3zw_25to30;  TH2 *h3zw_30to35;  TH2 *h3zw_35to40;  TH2 *h3zw_40to45;  TH2 *h3zw_45to50;  TH2 *h3zw_50to55; TH2 *h3zw_55to60;
    
    TH2 *hz_rec_gen;  TH2 *hzg_rec_gen;  TH2 *hzw_rec_gen;
    TH2 *hza_rec_gen;  TH2 *hzag_rec_gen;  TH2 *hzaw_rec_gen;
    
    
    TH2 *h6z_5to10;  TH2 *h6z_10to15;  TH2 *h6z_15to20;  TH2 *h6z_20to25;  TH2 *h6z_25to30;  TH2 *h6z_30to35;  TH2 *h6z_35to40;  TH2 *h6z_40to45;  TH2 *h6z_45to50;  TH2 *h6z_50to55; TH2 *h6z_55to60;
    TH2 *h7z_5to10;  TH2 *h7z_10to15;  TH2 *h7z_15to20;  TH2 *h7z_20to25;  TH2 *h7z_25to30;  TH2 *h7z_30to35;  TH2 *h7z_35to40;  TH2 *h7z_40to45;  TH2 *h7z_45to50;  TH2 *h7z_50to55; TH2 *h7z_55to60;
    TH2 *h8z_5to10;  TH2 *h8z_10to15;  TH2 *h8z_15to20;  TH2 *h8z_20to25;  TH2 *h8z_25to30;  TH2 *h8z_30to35;  TH2 *h8z_35to40;  TH2 *h8z_40to45;  TH2 *h8z_45to50;  TH2 *h8z_50to55; TH2 *h8z_55to60;
    TH2 *h12z_5to10;  TH2 *h12z_10to15;  TH2 *h12z_15to20;  TH2 *h12z_20to25;  TH2 *h12z_25to30;  TH2 *h12z_30to35;  TH2 *h12z_35to40;  TH2 *h12z_40to45;  TH2 *h12z_45to50;  TH2 *h12z_50to55; TH2 *h12z_55to60;
    TH2 *h13z_5to10;  TH2 *h13z_10to15;  TH2 *h13z_15to20;  TH2 *h13z_20to25;  TH2 *h13z_25to30;  TH2 *h13z_30to35;  TH2 *h13z_35to40;  TH2 *h13z_40to45;  TH2 *h13z_45to50;  TH2 *h13z_50to55; TH2 *h13z_55to60;
    TH2 *h14z_5to10;  TH2 *h14z_10to15;  TH2 *h14z_15to20;  TH2 *h14z_20to25;  TH2 *h14z_25to30;  TH2 *h14z_30to35;  TH2 *h14z_35to40;  TH2 *h14z_40to45;  TH2 *h14z_45to50;  TH2 *h14z_50to55; TH2 *h14z_55to60;
    TH2 *h15z_5to10;  TH2 *h15z_10to15;  TH2 *h15z_15to20;  TH2 *h15z_20to25;  TH2 *h15z_25to30;  TH2 *h15z_30to35;  TH2 *h15z_35to40;  TH2 *h15z_40to45;  TH2 *h15z_45to50;  TH2 *h15z_50to55; TH2 *h15z_55to60;
    TH2 *h16z_5to10;  TH2 *h16z_10to15;  TH2 *h16z_15to20;  TH2 *h16z_20to25;  TH2 *h16z_25to30;  TH2 *h16z_30to35;  TH2 *h16z_35to40;  TH2 *h16z_40to45;  TH2 *h16z_45to50;  TH2 *h16z_50to55; TH2 *h16z_55to60;
    TH2 *h17z_5to10;  TH2 *h17z_10to15;  TH2 *h17z_15to20;  TH2 *h17z_20to25;  TH2 *h17z_25to30;  TH2 *h17z_30to35;  TH2 *h17z_35to40;  TH2 *h17z_40to45;  TH2 *h17z_45to50;  TH2 *h17z_50to55; TH2 *h17z_55to60;
  
    
    
    
    TH1 *hsphericity;
    TH1 *htheta;

    TH1 *del_pt_E;
    TH1 *del_phi_E;
    TH1 *del_eta_E;

    TH1 *del_pt_g;
    TH1 *del_phi_g;
    TH1 *del_eta_g;

    TH1 *del_pt_w;
    TH1 *del_phi_w;
    TH1 *del_eta_w;
    
    TH1 *del_R_gen_rec_E_g_5to10;
    TH1 *del_R_gen_rec_E_W_5to10;
    TH1 *del_R_gen_rec_W_g_5to10;
    
    TH1 *del_R_gen_rec_E_g_10to15;
    TH1 *del_R_gen_rec_E_W_10to15;
    TH1 *del_R_gen_rec_W_g_10to15;
    
    TH1 *del_R_gen_rec_E_g_15to20;
    TH1 *del_R_gen_rec_E_W_15to20;
    TH1 *del_R_gen_rec_W_g_15to20;
    
    TH1 *del_R_gen_rec_E_g_20to25;
    TH1 *del_R_gen_rec_E_W_20to25;
    TH1 *del_R_gen_rec_W_g_20to25;
    
    TH1 *del_R_gen_rec_E_g_25to30;
    TH1 *del_R_gen_rec_E_W_25to30;
    TH1 *del_R_gen_rec_W_g_25to30;
    
    TH1 *del_R_gen_rec_E_g_30to35;
    TH1 *del_R_gen_rec_E_W_30to35;
    TH1 *del_R_gen_rec_W_g_30to35;
    
    TH1 *del_R_gen_rec_E_g_35to40;
    TH1 *del_R_gen_rec_E_W_35to40;
    TH1 *del_R_gen_rec_W_g_35to40;
    
    TH1 *del_R_gen_rec_E_g_40to45;
    TH1 *del_R_gen_rec_E_W_40to45;
    TH1 *del_R_gen_rec_W_g_40to45;
    
    TH1 *del_R_gen_rec_E_g_45to50;
    TH1 *del_R_gen_rec_E_W_45to50;
    TH1 *del_R_gen_rec_W_g_45to50;
    
    TH1 *del_R_gen_rec_E_g_50to55;
    TH1 *del_R_gen_rec_E_W_50to55;
    TH1 *del_R_gen_rec_W_g_50to55;
    
    TH1 *del_R_gen_rec_E_g_55to60;
    TH1 *del_R_gen_rec_E_W_55to60;
    TH1 *del_R_gen_rec_W_g_55to60;
    
    
    TH2 *del_R2_gen_rec_E_g_5to10;
    TH2 *del_R2_gen_rec_E_W_5to10;
    TH2 *del_R2_gen_rec_W_g_5to10;
    
    TH2 *del_R2_gen_rec_E_g_10to15;
    TH2 *del_R2_gen_rec_E_W_10to15;
    TH2 *del_R2_gen_rec_W_g_10to15;
    
    TH2 *del_R2_gen_rec_E_g_15to20;
    TH2 *del_R2_gen_rec_E_W_15to20;
    TH2 *del_R2_gen_rec_W_g_15to20;
    
    TH2 *del_R2_gen_rec_E_g_20to25;
    TH2 *del_R2_gen_rec_E_W_20to25;
    TH2 *del_R2_gen_rec_W_g_20to25;
    
    TH2 *del_R2_gen_rec_E_g_25to30;
    TH2 *del_R2_gen_rec_E_W_25to30;
    TH2 *del_R2_gen_rec_W_g_25to30;
    
    TH2 *del_R2_gen_rec_E_g_30to35;
    TH2 *del_R2_gen_rec_E_W_30to35;
    TH2 *del_R2_gen_rec_W_g_30to35;
    
    TH2 *del_R2_gen_rec_E_g_35to40;
    TH2 *del_R2_gen_rec_E_W_35to40;
    TH2 *del_R2_gen_rec_W_g_35to40;
    
    TH2 *del_R2_gen_rec_E_g_40to45;
    TH2 *del_R2_gen_rec_E_W_40to45;
    TH2 *del_R2_gen_rec_W_g_40to45;
    
    TH2 *del_R2_gen_rec_E_g_45to50;
    TH2 *del_R2_gen_rec_E_W_45to50;
    TH2 *del_R2_gen_rec_W_g_45to50;
    
    TH2 *del_R2_gen_rec_E_g_50to55;
    TH2 *del_R2_gen_rec_E_W_50to55;
    TH2 *del_R2_gen_rec_W_g_50to55;
    
    TH2 *del_R2_gen_rec_E_g_55to60;
    TH2 *del_R2_gen_rec_E_W_55to60;
    TH2 *del_R2_gen_rec_W_g_55to60;
    
    
    
    TH2 *p_vs_theta;
    
    hsphericity = new TH1F("hsphericity","Sphericity",100,-0.1,1);
    htheta = new TH1F("htheta","STheta",100,-0.1,3.5);
    
    h1a = new TH1F("h1a","rec gen E scheme Jt pt",1000,0,60);
    h1a->SetLineColor(kBlue);
   h1b = new TH1F("h1b","rec gen Wta Jt pt",1000,0,60);
    h1b->SetLineColor(kBlue);
   h1c = new TH1F("h1c","rec gen groomed Jt pt",1000,0,60);
    h1c->SetLineColor(kBlue);
     h1d = new TH1F("h1d","rec gen E scheme Jt pt",1000,0,60);
    h1d->SetLineColor(kRed);
   h1e = new TH1F("h1e","rec gen Wta Jt pt",1000,0,60);
    h1e->SetLineColor(kRed);
   h1f = new TH1F("h1f","rec gen groomed Jt pt",1000,0,60);
    h1f->SetLineColor(kRed);
    
    
    hz_rec_gen = new TH2F("hz_rec_gen","rec gen p E",41,5,46,95,5,100);
    hz_rec_gen->GetXaxis()->SetTitle("gen p"); hz_rec_gen->GetYaxis()->SetTitle("rec p");
    hz_rec_gen->GetXaxis()->SetLabelSize(0.05); hz_rec_gen->GetYaxis()->SetLabelSize(0.05);
    hz_rec_gen->GetXaxis()->SetTitleSize(0.05);hz_rec_gen->GetYaxis()->SetTitleSize(0.05);
    hzg_rec_gen = new TH2F("hzg_rec_gen","rec gen p G",41,5,46,95,5,100);
    hzg_rec_gen->GetXaxis()->SetTitle("gen p"); hzg_rec_gen->GetYaxis()->SetTitle("rec p");
    hzg_rec_gen->GetXaxis()->SetLabelSize(0.05); hzg_rec_gen->GetYaxis()->SetLabelSize(0.05);
    hzg_rec_gen->GetXaxis()->SetTitleSize(0.05); hzg_rec_gen->GetYaxis()->SetTitleSize(0.05);
    hzw_rec_gen = new TH2F("hzw_rec_gen","rec gen p W",41,5,46,95,5,100);
    hzw_rec_gen->GetXaxis()->SetTitle("gen p"); hzw_rec_gen->GetYaxis()->SetTitle("rec p");
    hzw_rec_gen->GetXaxis()->SetLabelSize(0.05); hzw_rec_gen->GetYaxis()->SetLabelSize(0.05);
    hzw_rec_gen->GetXaxis()->SetTitleSize(0.05); hzw_rec_gen->GetYaxis()->SetTitleSize(0.05);
    
    hza_rec_gen = new TH2F("hza_rec_gen","rec gen p E",41,5,46,95,5,100);
    hza_rec_gen->GetXaxis()->SetTitle("gen p"); hza_rec_gen->GetYaxis()->SetTitle("rec p");
    hza_rec_gen->GetXaxis()->SetLabelSize(0.05); hza_rec_gen->GetYaxis()->SetLabelSize(0.05);
    hza_rec_gen->GetXaxis()->SetTitleSize(0.05); hza_rec_gen->GetYaxis()->SetTitleSize(0.05);
    hzag_rec_gen = new TH2F("hzag_rec_gen","rec gen p G",41,5,46,95,5,100);
    hzag_rec_gen->GetXaxis()->SetTitle("gen p"); hzag_rec_gen->GetYaxis()->SetTitle("rec p");
    hzag_rec_gen->GetXaxis()->SetLabelSize(0.05); hzag_rec_gen->GetYaxis()->SetLabelSize(0.05);
    hzag_rec_gen->GetXaxis()->SetTitleSize(0.05); hzag_rec_gen->GetYaxis()->SetTitleSize(0.05);
    hzaw_rec_gen = new TH2F("hzaw_rec_gen","rec gen p W",41,5,46,95,5,100);
    hzaw_rec_gen->GetXaxis()->SetTitle("gen p"); hzaw_rec_gen->GetYaxis()->SetTitle("rec p");
    hzaw_rec_gen->GetXaxis()->SetLabelSize(0.05); hzaw_rec_gen->GetYaxis()->SetLabelSize(0.05);
    hzaw_rec_gen->GetXaxis()->SetTitleSize(0.05); hzaw_rec_gen->GetYaxis()->SetTitleSize(0.05);

    
    h1z_5to10 = new TH2F("h1z_5to10","rec gen p 5to10",5,5,10,5,5,10);
    h1z_5to10->GetXaxis()->SetTitle("Gen p"); h1z_5to10->GetYaxis()->SetTitle("Rec p");
    h1z_5to10->GetXaxis()->SetLabelSize(0.05);h1z_5to10->GetYaxis()->SetLabelSize(0.05);
    h1z_5to10->GetXaxis()->SetTitleSize(0.05);h1z_5to10->GetYaxis()->SetTitleSize(0.05);
    h1z_10to15 = new TH2F("h1z_10to15","rec gen p 10to15",5,10,15,5,10,15);
    h1z_10to15->GetXaxis()->SetTitle("Gen p"); h1z_10to15->GetYaxis()->SetTitle("Rec p");
    h1z_10to15->GetXaxis()->SetLabelSize(0.05);h1z_10to15->GetYaxis()->SetLabelSize(0.05);
    h1z_10to15->GetXaxis()->SetTitleSize(0.05);h1z_10to15->GetYaxis()->SetTitleSize(0.05);
    h1z_15to20 = new TH2F("h1z_15to20","rec gen p 15to20",5,15,20,5,15,20);
    h1z_15to20->GetXaxis()->SetTitle("Gen p"); h1z_15to20->GetYaxis()->SetTitle("Rec p");
    h1z_15to20->GetXaxis()->SetLabelSize(0.05);h1z_15to20->GetYaxis()->SetLabelSize(0.05);
    h1z_15to20->GetXaxis()->SetTitleSize(0.05);h1z_15to20->GetYaxis()->SetTitleSize(0.05);
    h1z_20to25 = new TH2F("h1z_20to25","rec gen p 20to25",5,20,25,5,20,25);
    h1z_20to25->GetXaxis()->SetTitle("Gen p"); h1z_20to25->GetYaxis()->SetTitle("Rec p");
    h1z_20to25->GetXaxis()->SetLabelSize(0.05);h1z_20to25->GetYaxis()->SetLabelSize(0.05);
    h1z_20to25->GetXaxis()->SetTitleSize(0.05);h1z_20to25->GetYaxis()->SetTitleSize(0.05);
    h1z_25to30 = new TH2F("h1z_25to30","rec gen p 25to30",5,25,30,5,25,30);
    h1z_25to30->GetXaxis()->SetTitle("Gen p"); h1z_25to30->GetYaxis()->SetTitle("Rec p");
    h1z_25to30->GetXaxis()->SetLabelSize(0.05);h1z_25to30->GetYaxis()->SetLabelSize(0.05);
    h1z_25to30->GetXaxis()->SetTitleSize(0.05);h1z_25to30->GetYaxis()->SetTitleSize(0.05);
    h1z_30to35 = new TH2F("h1z_30to35","rec gen p 30to35",5,30,35,5,30,35);
    h1z_30to35->GetXaxis()->SetTitle("Gen p"); h1z_30to35->GetYaxis()->SetTitle("Rec p");
    h1z_30to35->GetXaxis()->SetLabelSize(0.05);h1z_30to35->GetYaxis()->SetLabelSize(0.05);
    h1z_30to35->GetXaxis()->SetTitleSize(0.05);h1z_30to35->GetYaxis()->SetTitleSize(0.05);
    h1z_35to40 = new TH2F("h1z_35to40","rec gen p 35to40",5,35,40,5,35,40);
    h1z_35to40->GetXaxis()->SetTitle("Gen p"); h1z_35to40->GetYaxis()->SetTitle("Rec p");
    h1z_35to40->GetXaxis()->SetLabelSize(0.05);h1z_35to40->GetYaxis()->SetLabelSize(0.05);
    h1z_35to40->GetXaxis()->SetTitleSize(0.05);h1z_35to40->GetYaxis()->SetTitleSize(0.05);
    h1z_40to45 = new TH2F("h1z_40to45","rec gen p 40to45",5,40,45,5,40,45);
    h1z_40to45->GetXaxis()->SetTitle("Gen p"); h1z_40to45->GetYaxis()->SetTitle("Rec p");
    h1z_40to45->GetXaxis()->SetLabelSize(0.05);h1z_40to45->GetYaxis()->SetLabelSize(0.05);
    h1z_40to45->GetXaxis()->SetTitleSize(0.05);h1z_40to45->GetYaxis()->SetTitleSize(0.05);
    h1z_45to50 = new TH2F("h1z_45to50","rec gen p 45to50",5,45,50,5,45,50);
    h1z_45to50->GetXaxis()->SetTitle("Gen p"); h1z_45to50->GetYaxis()->SetTitle("Rec p");
    h1z_45to50->GetXaxis()->SetLabelSize(0.05);h1z_45to50->GetYaxis()->SetLabelSize(0.05);
    h1z_45to50->GetXaxis()->SetTitleSize(0.05);h1z_45to50->GetYaxis()->SetTitleSize(0.05);
    h1z_50to55 = new TH2F("h1z_50to55","rec gen p 50to55",5,50,55,5,50,55);
    h1z_50to55->GetXaxis()->SetTitle("Gen p"); h1z_50to55->GetYaxis()->SetTitle("Rec p");
    h1z_50to55->GetXaxis()->SetLabelSize(0.05);h1z_50to55->GetYaxis()->SetLabelSize(0.05);
    h1z_50to55->GetXaxis()->SetTitleSize(0.05);h1z_50to55->GetYaxis()->SetTitleSize(0.05);
    h1z_55to60 = new TH2F("h1z_55to60","rec gen p 55to60",5,55,60,5,55,60);
    h1z_55to60->GetXaxis()->SetTitle("Gen p"); h1z_55to60->GetYaxis()->SetTitle("Rec p");
    h1z_55to60->GetXaxis()->SetLabelSize(0.05);h1z_55to60->GetYaxis()->SetLabelSize(0.05);
    h1z_55to60->GetXaxis()->SetTitleSize(0.05);h1z_55to60->GetYaxis()->SetTitleSize(0.05);
    
    
    h2z_5to10 = new TH2F("h2z_5to10","rec gen phi 5to10",1000,0,3.2,1000,0,3.2);
    h2z_5to10->GetXaxis()->SetTitle("Gen phi"); h2z_5to10->GetYaxis()->SetTitle("Rec phi");
    h2z_5to10->GetXaxis()->SetLabelSize(0.05);h2z_5to10->GetYaxis()->SetLabelSize(0.05);
    h2z_5to10->GetXaxis()->SetTitleSize(0.05);h2z_5to10->GetYaxis()->SetTitleSize(0.05);
    h2z_10to15 = new TH2F("h2z_10to15","rec gen phi 10to15",1000,0,3.2,1000,0,3.2);
    h2z_10to15->GetXaxis()->SetTitle("Gen phi"); h2z_10to15->GetYaxis()->SetTitle("Rec phi");
    h2z_10to15->GetXaxis()->SetLabelSize(0.05);h2z_10to15->GetYaxis()->SetLabelSize(0.05);
    h2z_10to15->GetXaxis()->SetTitleSize(0.05);h2z_10to15->GetYaxis()->SetTitleSize(0.05);
    h2z_15to20 = new TH2F("h2z_15to20","rec gen phi 15to20",1000,0,3.2,1000,0,3.2);
    h2z_15to20->GetXaxis()->SetTitle("Gen phi"); h2z_15to20->GetYaxis()->SetTitle("Rec phi");
    h2z_15to20->GetXaxis()->SetLabelSize(0.05);h2z_15to20->GetYaxis()->SetLabelSize(0.05);
    h2z_15to20->GetXaxis()->SetTitleSize(0.05);h2z_15to20->GetYaxis()->SetTitleSize(0.05);
    h2z_20to25 = new TH2F("h2z_20to25","rec gen phi 20to25",1000,0,3.2,1000,0,3.2);
    h2z_20to25->GetXaxis()->SetTitle("Gen phi"); h2z_20to25->GetYaxis()->SetTitle("Rec phi");
    h2z_20to25->GetXaxis()->SetLabelSize(0.05);h2z_20to25->GetYaxis()->SetLabelSize(0.05);
    h2z_20to25->GetXaxis()->SetTitleSize(0.05);h2z_20to25->GetYaxis()->SetTitleSize(0.05);
    h2z_25to30 = new TH2F("h2z_25to30","rec gen phi 25to30",1000,0,3.2,1000,0,3.2);
    h2z_25to30->GetXaxis()->SetTitle("Gen phi"); h2z_25to30->GetYaxis()->SetTitle("Rec phi");
    h2z_25to30->GetXaxis()->SetLabelSize(0.05);h2z_25to30->GetYaxis()->SetLabelSize(0.05);
    h2z_25to30->GetXaxis()->SetTitleSize(0.05);h2z_25to30->GetYaxis()->SetTitleSize(0.05);
    h2z_30to35 = new TH2F("h2z_30to35","rec gen phi 30to35",1000,0,3.2,1000,0,3.2);
    h2z_30to35->GetXaxis()->SetTitle("Gen phi"); h2z_30to35->GetYaxis()->SetTitle("Rec phi");
    h2z_30to35->GetXaxis()->SetLabelSize(0.05);h2z_30to35->GetYaxis()->SetLabelSize(0.05);
    h2z_30to35->GetXaxis()->SetTitleSize(0.05);h2z_30to35->GetYaxis()->SetTitleSize(0.05);
    h2z_35to40 = new TH2F("h2z_35to40","rec gen phi 35to40",1000,0,3.2,1000,0,3.2);
    h2z_35to40->GetXaxis()->SetTitle("Gen phi"); h2z_35to40->GetYaxis()->SetTitle("Rec phi");
    h2z_35to40->GetXaxis()->SetLabelSize(0.05);h2z_35to40->GetYaxis()->SetLabelSize(0.05);
    h2z_35to40->GetXaxis()->SetTitleSize(0.05);h2z_35to40->GetYaxis()->SetTitleSize(0.05);
    h2z_40to45 = new TH2F("h2z_40to45","rec gen phi 40to45",1000,0,3.2,1000,0,3.2);
    h2z_40to45->GetXaxis()->SetTitle("Gen phi"); h2z_40to45->GetYaxis()->SetTitle("Rec phi");
    h2z_40to45->GetXaxis()->SetLabelSize(0.05);h2z_40to45->GetYaxis()->SetLabelSize(0.05);
    h2z_40to45->GetXaxis()->SetTitleSize(0.05);h2z_40to45->GetYaxis()->SetTitleSize(0.05);
    h2z_45to50 = new TH2F("h2z_45to50","rec gen phi 45to50",1000,0,3.2,1000,0,3.2);
    h2z_45to50->GetXaxis()->SetTitle("Gen phi"); h2z_45to50->GetYaxis()->SetTitle("Rec phi");
    h2z_45to50->GetXaxis()->SetLabelSize(0.05);h2z_45to50->GetYaxis()->SetLabelSize(0.05);
    h2z_45to50->GetXaxis()->SetTitleSize(0.05);h2z_45to50->GetYaxis()->SetTitleSize(0.05);
    h2z_50to55 = new TH2F("h2z_50to55","rec gen phi 50to55",1000,0,3.2,1000,0,3.2);
    h2z_50to55->GetXaxis()->SetTitle("Gen phi"); h2z_50to55->GetYaxis()->SetTitle("Rec phi");
    h2z_50to55->GetXaxis()->SetLabelSize(0.05);h2z_50to55->GetYaxis()->SetLabelSize(0.05);
    h2z_50to55->GetXaxis()->SetTitleSize(0.05);h2z_50to55->GetYaxis()->SetTitleSize(0.05);
    h2z_55to60 = new TH2F("h2z_55to60","rec gen phi 55to60",1000,0,3.2,1000,0,3.2);
    h2z_55to60->GetXaxis()->SetTitle("Gen phi"); h2z_55to60->GetYaxis()->SetTitle("Rec phi");
    h2z_55to60->GetXaxis()->SetLabelSize(0.05);h2z_55to60->GetYaxis()->SetLabelSize(0.05);
    h2z_55to60->GetXaxis()->SetTitleSize(0.05);h2z_55to60->GetYaxis()->SetTitleSize(0.05);
    
    
    h3z_5to10 = new TH2F("h3z_5to10","rec gen theta 5to10",1000,0,3.2,1000,0,3.2);
    h3z_5to10->GetXaxis()->SetTitle("Gen theta"); h3z_5to10->GetYaxis()->SetTitle("Rec theta");
    h3z_5to10->GetXaxis()->SetLabelSize(0.05);h3z_5to10->GetYaxis()->SetLabelSize(0.05);
    h3z_5to10->GetXaxis()->SetTitleSize(0.05);h3z_5to10->GetYaxis()->SetTitleSize(0.05);
    h3z_10to15 = new TH2F("h3z_10to15","rec gen theta 10to15",1000,0,3.2,1000,0,3.2);
    h3z_10to15->GetXaxis()->SetTitle("Gen theta"); h3z_10to15->GetYaxis()->SetTitle("Rec theta");
    h3z_10to15->GetXaxis()->SetLabelSize(0.05);h3z_10to15->GetYaxis()->SetLabelSize(0.05);
    h3z_10to15->GetXaxis()->SetTitleSize(0.05);h3z_10to15->GetYaxis()->SetTitleSize(0.05);
    h3z_15to20 = new TH2F("h3z_15to20","rec gen theta 15to20",1000,0,3.2,1000,0,3.2);
    h3z_15to20->GetXaxis()->SetTitle("Gen theta"); h3z_15to20->GetYaxis()->SetTitle("Rec theta");
    h3z_15to20->GetXaxis()->SetLabelSize(0.05);h3z_15to20->GetYaxis()->SetLabelSize(0.05);
    h3z_15to20->GetXaxis()->SetTitleSize(0.05);h3z_15to20->GetYaxis()->SetTitleSize(0.05);
    h3z_20to25 = new TH2F("h3z_20to25","rec gen theta 20to25",1000,0,3.2,1000,0,3.2);
    h3z_20to25->GetXaxis()->SetTitle("Gen theta"); h3z_20to25->GetYaxis()->SetTitle("Rec theta");
    h3z_20to25->GetXaxis()->SetLabelSize(0.05);h3z_20to25->GetYaxis()->SetLabelSize(0.05);
    h3z_20to25->GetXaxis()->SetTitleSize(0.05);h3z_20to25->GetYaxis()->SetTitleSize(0.05);
    h3z_25to30 = new TH2F("h3z_25to30","rec gen theta 25to30",1000,0,3.2,1000,0,3.2);
    h3z_25to30->GetXaxis()->SetTitle("Gen theta"); h3z_25to30->GetYaxis()->SetTitle("Rec theta");
    h3z_25to30->GetXaxis()->SetLabelSize(0.05);h3z_25to30->GetYaxis()->SetLabelSize(0.05);
    h3z_25to30->GetXaxis()->SetTitleSize(0.05);h3z_25to30->GetYaxis()->SetTitleSize(0.05);
    h3z_30to35 = new TH2F("h3z_30to35","rec gen theta 30to35",1000,0,3.2,1000,0,3.2);
    h3z_30to35->GetXaxis()->SetTitle("Gen theta"); h3z_30to35->GetYaxis()->SetTitle("Rec theta");
    h3z_30to35->GetXaxis()->SetLabelSize(0.05);h3z_30to35->GetYaxis()->SetLabelSize(0.05);
    h3z_30to35->GetXaxis()->SetTitleSize(0.05);h3z_30to35->GetYaxis()->SetTitleSize(0.05);
    h3z_35to40 = new TH2F("h3z_35to40","rec gen theta 35to40",1000,0,3.2,1000,0,3.2);
    h3z_35to40->GetXaxis()->SetTitle("Gen theta"); h3z_35to40->GetYaxis()->SetTitle("Rec theta");
    h3z_35to40->GetXaxis()->SetLabelSize(0.05);h3z_35to40->GetYaxis()->SetLabelSize(0.05);
    h3z_35to40->GetXaxis()->SetTitleSize(0.05);h3z_35to40->GetYaxis()->SetTitleSize(0.05);
    h3z_40to45 = new TH2F("h3z_40to45","rec gen theta 40to45",1000,0,3.2,1000,0,3.2);
    h3z_40to45->GetXaxis()->SetTitle("Gen theta"); h3z_40to45->GetYaxis()->SetTitle("Rec theta");
    h3z_40to45->GetXaxis()->SetLabelSize(0.05);h3z_40to45->GetYaxis()->SetLabelSize(0.05);
    h3z_40to45->GetXaxis()->SetTitleSize(0.05);h3z_40to45->GetYaxis()->SetTitleSize(0.05);
    h3z_45to50 = new TH2F("h3z_45to50","rec gen theta 45to50",1000,0,3.2,1000,0,3.2);
    h3z_45to50->GetXaxis()->SetTitle("Gen theta"); h3z_45to50->GetYaxis()->SetTitle("Rec theta");
    h3z_45to50->GetXaxis()->SetLabelSize(0.05);h3z_45to50->GetYaxis()->SetLabelSize(0.05);
    h3z_45to50->GetXaxis()->SetTitleSize(0.05);h3z_45to50->GetYaxis()->SetTitleSize(0.05);
    h3z_50to55 = new TH2F("h3z_50to55","rec gen theta 50to55",1000,0,3.2,1000,0,3.2);
    h3z_50to55->GetXaxis()->SetTitle("Gen theta"); h3z_50to55->GetYaxis()->SetTitle("Rec theta");
    h3z_50to55->GetXaxis()->SetLabelSize(0.05);h3z_50to55->GetYaxis()->SetLabelSize(0.05);
    h3z_50to55->GetXaxis()->SetTitleSize(0.05);h3z_50to55->GetYaxis()->SetTitleSize(0.05);
    h3z_55to60 = new TH2F("h3z_55to60","rec gen theta 55to60",1000,0,3.2,1000,0,3.2);
    h3z_55to60->GetXaxis()->SetTitle("Gen theta"); h3z_55to60->GetYaxis()->SetTitle("Rec theta");
    h3z_55to60->GetXaxis()->SetLabelSize(0.05);h3z_55to60->GetYaxis()->SetLabelSize(0.05);
    h3z_55to60->GetXaxis()->SetTitleSize(0.05);h3z_55to60->GetYaxis()->SetTitleSize(0.05);
    
    
    h1zg_5to10 = new TH2F("h1zg_5to10","g rec gen p 5to10",5,5,10,5,5,10);
    h1zg_5to10->GetXaxis()->SetTitle("Gen p"); h1zg_5to10->GetYaxis()->SetTitle("Rec p");
    h1zg_5to10->GetXaxis()->SetLabelSize(0.05);h1zg_5to10->GetYaxis()->SetLabelSize(0.05);
    h1zg_5to10->GetXaxis()->SetTitleSize(0.05);h1zg_5to10->GetYaxis()->SetTitleSize(0.05);
    h1zg_10to15 = new TH2F("h1zg_10to15","g rec gen p 10to15",5,10,15,5,10,15);
    h1zg_10to15->GetXaxis()->SetTitle("Gen p"); h1zg_10to15->GetYaxis()->SetTitle("Rec p");
    h1zg_10to15->GetXaxis()->SetLabelSize(0.05);h1zg_10to15->GetYaxis()->SetLabelSize(0.05);
    h1zg_10to15->GetXaxis()->SetTitleSize(0.05);h1zg_10to15->GetYaxis()->SetTitleSize(0.05);
    h1zg_15to20 = new TH2F("h1zg_15to20","g rec gen p 15to20",5,15,20,5,15,20);
    h1zg_15to20->GetXaxis()->SetTitle("Gen p"); h1zg_15to20->GetYaxis()->SetTitle("Rec p");
    h1zg_15to20->GetXaxis()->SetLabelSize(0.05);h1zg_15to20->GetYaxis()->SetLabelSize(0.05);
    h1zg_15to20->GetXaxis()->SetTitleSize(0.05);h1zg_15to20->GetYaxis()->SetTitleSize(0.05);
    h1zg_20to25 = new TH2F("h1zg_20to25","g rec gen p 20to25",5,20,25,5,20,25);
    h1zg_20to25->GetXaxis()->SetTitle("Gen p"); h1zg_20to25->GetYaxis()->SetTitle("Rec p");
    h1zg_20to25->GetXaxis()->SetLabelSize(0.05);h1zg_20to25->GetYaxis()->SetLabelSize(0.05);
    h1zg_20to25->GetXaxis()->SetTitleSize(0.05);h1zg_20to25->GetYaxis()->SetTitleSize(0.05);
    h1zg_25to30 = new TH2F("h1zg_25to30","grec gen p 25to30",5,25,30,5,25,30);
    h1zg_25to30->GetXaxis()->SetTitle("Gen p"); h1zg_25to30->GetYaxis()->SetTitle("Rec p");
    h1zg_25to30->GetXaxis()->SetLabelSize(0.05);h1zg_25to30->GetYaxis()->SetLabelSize(0.05);
    h1zg_25to30->GetXaxis()->SetTitleSize(0.05);h1zg_25to30->GetYaxis()->SetTitleSize(0.05);
    h1zg_30to35 = new TH2F("h1zg_30to35","g rec gen p 30to35",5,30,35,5,30,35);
    h1zg_30to35->GetXaxis()->SetTitle("Gen p"); h1zg_30to35->GetYaxis()->SetTitle("Rec p");
    h1zg_30to35->GetXaxis()->SetLabelSize(0.05);h1zg_30to35->GetYaxis()->SetLabelSize(0.05);
    h1zg_30to35->GetXaxis()->SetTitleSize(0.05);h1zg_30to35->GetYaxis()->SetTitleSize(0.05);
    h1zg_35to40 = new TH2F("h1zg_35to40","g rec gen p 35to40",5,35,40,5,35,40);
    h1zg_35to40->GetXaxis()->SetTitle("Gen p"); h1zg_35to40->GetYaxis()->SetTitle("Rec p");
    h1zg_35to40->GetXaxis()->SetLabelSize(0.05);h1zg_35to40->GetYaxis()->SetLabelSize(0.05);
    h1zg_35to40->GetXaxis()->SetTitleSize(0.05);h1zg_35to40->GetYaxis()->SetTitleSize(0.05);
    h1zg_40to45 = new TH2F("h1zg_40to45","g rec gen p 40to45",5,40,45,5,40,45);
    h1zg_40to45->GetXaxis()->SetTitle("Gen p"); h1zg_40to45->GetYaxis()->SetTitle("Rec p");
    h1zg_40to45->GetXaxis()->SetLabelSize(0.05);h1zg_40to45->GetYaxis()->SetLabelSize(0.05);
    h1zg_40to45->GetXaxis()->SetTitleSize(0.05);h1zg_40to45->GetYaxis()->SetTitleSize(0.05);
    h1zg_45to50 = new TH2F("h1zg_45to50","g rec gen p 45to50",5,45,50,5,45,50);
    h1zg_45to50->GetXaxis()->SetTitle("Gen p"); h1zg_45to50->GetYaxis()->SetTitle("Rec p");
    h1zg_45to50->GetXaxis()->SetLabelSize(0.05);h1zg_45to50->GetYaxis()->SetLabelSize(0.05);
    h1zg_45to50->GetXaxis()->SetTitleSize(0.05);h1zg_45to50->GetYaxis()->SetTitleSize(0.05);
    h1zg_50to55 = new TH2F("h1zg_50to55","g rec gen p 50to55",5,50,55,5,50,55);
    h1zg_50to55->GetXaxis()->SetTitle("Gen p"); h1zg_50to55->GetYaxis()->SetTitle("Rec p");
    h1zg_50to55->GetXaxis()->SetLabelSize(0.05);h1zg_50to55->GetYaxis()->SetLabelSize(0.05);
    h1zg_50to55->GetXaxis()->SetTitleSize(0.05);h1zg_50to55->GetYaxis()->SetTitleSize(0.05);
    h1zg_55to60 = new TH2F("h1zg_55to60","g rec gen p 55to60",5,55,60,5,55,60);
    h1zg_55to60->GetXaxis()->SetTitle("Gen p"); h1zg_55to60->GetYaxis()->SetTitle("Rec p");
    h1zg_55to60->GetXaxis()->SetLabelSize(0.05);h1zg_55to60->GetYaxis()->SetLabelSize(0.05);
    h1zg_55to60->GetXaxis()->SetTitleSize(0.05);h1zg_55to60->GetYaxis()->SetTitleSize(0.05);
    
    
    h2zg_5to10 = new TH2F("h2zg_5to10","g rec gen phi 5to10",1000,0,3.2,1000,0,3.2);
    h2zg_5to10->GetXaxis()->SetTitle("Gen phi"); h2zg_5to10->GetYaxis()->SetTitle("Rec phi");
    h2zg_5to10->GetXaxis()->SetLabelSize(0.05);h2zg_5to10->GetYaxis()->SetLabelSize(0.05);
    h2zg_5to10->GetXaxis()->SetTitleSize(0.05);h2zg_5to10->GetYaxis()->SetTitleSize(0.05);
    h2zg_10to15 = new TH2F("h2zg_10to15","g rec gen phi 10to15",1000,0,3.2,1000,0,3.2);
    h2zg_10to15->GetXaxis()->SetTitle("Gen phi"); h2zg_10to15->GetYaxis()->SetTitle("Rec phi");
    h2zg_10to15->GetXaxis()->SetLabelSize(0.05);h2zg_10to15->GetYaxis()->SetLabelSize(0.05);
    h2zg_10to15->GetXaxis()->SetTitleSize(0.05);h2zg_10to15->GetYaxis()->SetTitleSize(0.05);
    h2zg_15to20 = new TH2F("h2zg_15to20","g rec gen phi 15to20",1000,0,3.2,1000,0,3.2);
    h2zg_15to20->GetXaxis()->SetTitle("Gen phi"); h2zg_15to20->GetYaxis()->SetTitle("Rec phi");
    h2zg_15to20->GetXaxis()->SetLabelSize(0.05);h2zg_15to20->GetYaxis()->SetLabelSize(0.05);
    h2zg_15to20->GetXaxis()->SetTitleSize(0.05);h2zg_15to20->GetYaxis()->SetTitleSize(0.05);
    h2zg_20to25 = new TH2F("h2zg_20to25","g rec gen phi 20to25",1000,0,3.2,1000,0,3.2);
    h2zg_20to25->GetXaxis()->SetTitle("Gen phi"); h2zg_20to25->GetYaxis()->SetTitle("Rec phi");
    h2zg_20to25->GetXaxis()->SetLabelSize(0.05);h2zg_20to25->GetYaxis()->SetLabelSize(0.05);
    h2zg_20to25->GetXaxis()->SetTitleSize(0.05);h2zg_20to25->GetYaxis()->SetTitleSize(0.05);
    h2zg_25to30 = new TH2F("h2zg_25to30","g rec gen phi 25to30",1000,0,3.2,1000,0,3.2);
    h2zg_25to30->GetXaxis()->SetTitle("Gen phi"); h2zg_25to30->GetYaxis()->SetTitle("Rec phi");
    h2zg_25to30->GetXaxis()->SetLabelSize(0.05); h2zg_25to30->GetYaxis()->SetLabelSize(0.05);
    h2zg_25to30->GetXaxis()->SetTitleSize(0.05);h2zg_25to30->GetYaxis()->SetTitleSize(0.05);
    h2zg_30to35 = new TH2F("h2zg_30to35","g rec gen phi 30to35",1000,0,3.2,1000,0,3.2);
    h2zg_30to35->GetXaxis()->SetTitle("Gen phi"); h2zg_30to35->GetYaxis()->SetTitle("Rec phi");
    h2zg_30to35->GetXaxis()->SetLabelSize(0.05);h2zg_30to35->GetYaxis()->SetLabelSize(0.05);
    h2zg_30to35->GetXaxis()->SetTitleSize(0.05);h2zg_30to35->GetYaxis()->SetTitleSize(0.05);
    h2zg_35to40 = new TH2F("h2zg_35to40","g rec gen phi 35to40",1000,0,3.2,1000,0,3.2);
    h2zg_35to40->GetXaxis()->SetTitle("Gen phi"); h2zg_35to40->GetYaxis()->SetTitle("Rec phi");
    h2zg_35to40->GetXaxis()->SetLabelSize(0.05);h2zg_35to40->GetYaxis()->SetLabelSize(0.05);
    h2zg_35to40->GetXaxis()->SetTitleSize(0.05);h2zg_35to40->GetYaxis()->SetTitleSize(0.05);
    h2zg_40to45 = new TH2F("h2zg_40to45","g rec gen phi 40to45",1000,0,3.2,1000,0,3.2);
    h2zg_40to45->GetXaxis()->SetTitle("Gen phi"); h2zg_40to45->GetYaxis()->SetTitle("Rec phi");
    h2zg_40to45->GetXaxis()->SetLabelSize(0.05);h2zg_40to45->GetYaxis()->SetLabelSize(0.05);
    h2zg_40to45->GetXaxis()->SetTitleSize(0.05);h2zg_40to45->GetYaxis()->SetTitleSize(0.05);
    h2zg_45to50 = new TH2F("h2zg_45to50","g rec gen phi 45to50",1000,0,3.2,1000,0,3.2);
    h2zg_45to50->GetXaxis()->SetTitle("Gen phi"); h2zg_45to50->GetYaxis()->SetTitle("Rec phi");
    h2zg_45to50->GetXaxis()->SetLabelSize(0.05);h2zg_45to50->GetYaxis()->SetLabelSize(0.05);
    h2zg_45to50->GetXaxis()->SetTitleSize(0.05);h2zg_45to50->GetYaxis()->SetTitleSize(0.05);
    h2zg_50to55 = new TH2F("h2zg_50to55","g rec gen phi 50to55",1000,0,3.2,1000,0,3.2);
    h2zg_50to55->GetXaxis()->SetTitle("Gen phi"); h2zg_50to55->GetYaxis()->SetTitle("Rec phi");
    h2zg_50to55->GetXaxis()->SetLabelSize(0.05);h2zg_50to55->GetYaxis()->SetLabelSize(0.05);
    h2zg_50to55->GetXaxis()->SetTitleSize(0.05);h2zg_50to55->GetYaxis()->SetTitleSize(0.05);
    h2zg_55to60 = new TH2F("h2zg_55to60","g rec gen phi 55to60",1000,0,3.2,1000,0,3.2);
    h2zg_55to60->GetXaxis()->SetTitle("Gen phi"); h2zg_55to60->GetYaxis()->SetTitle("Rec phi");
    h2zg_55to60->GetXaxis()->SetLabelSize(0.05);h2zg_55to60->GetYaxis()->SetLabelSize(0.05);
    h2zg_55to60->GetXaxis()->SetTitleSize(0.05);h2zg_55to60->GetYaxis()->SetTitleSize(0.05);
    
    
    h3zg_5to10 = new TH2F("h3zg_5to10","g rec gen theta 5to10",1000,0,3.2,1000,0,3.2);
    h3zg_5to10->GetXaxis()->SetTitle("Gen theta"); h3zg_5to10->GetYaxis()->SetTitle("Rec theta");
    h3zg_5to10->GetXaxis()->SetLabelSize(0.05);h3zg_5to10->GetYaxis()->SetLabelSize(0.05);
    h3zg_5to10->GetXaxis()->SetTitleSize(0.05);h3zg_5to10->GetYaxis()->SetTitleSize(0.05);
    h3zg_10to15 = new TH2F("h3zg_10to15","g rec gen theta 10to15",1000,0,3.2,1000,0,3.2);
    h3zg_10to15->GetXaxis()->SetTitle("Gen theta"); h3zg_10to15->GetYaxis()->SetTitle("Rec theta");
    h3zg_10to15->GetXaxis()->SetLabelSize(0.05);h3zg_10to15->GetYaxis()->SetLabelSize(0.05);
    h3zg_10to15->GetXaxis()->SetTitleSize(0.05);h3zg_10to15->GetYaxis()->SetTitleSize(0.05);
    h3zg_15to20 = new TH2F("h3zg_15to20","g rec gen theta 15to20",1000,0,3.2,1000,0,3.2);
    h3zg_15to20->GetXaxis()->SetTitle("Gen theta"); h3zg_15to20->GetYaxis()->SetTitle("Rec theta");
    h3zg_15to20->GetXaxis()->SetLabelSize(0.05);h3zg_15to20->GetYaxis()->SetLabelSize(0.05);
    h3zg_15to20->GetXaxis()->SetTitleSize(0.05);h3zg_15to20->GetYaxis()->SetTitleSize(0.05);
    h3zg_20to25 = new TH2F("h3zg_20to25","g rec gen theta 20to25",1000,0,3.2,1000,0,3.2);
    h3zg_20to25->GetXaxis()->SetTitle("Gen theta"); h3zg_20to25->GetYaxis()->SetTitle("Rec theta");
    h3zg_20to25->GetXaxis()->SetLabelSize(0.05);h3zg_20to25->GetYaxis()->SetLabelSize(0.05);
    h3zg_20to25->GetXaxis()->SetTitleSize(0.05);h3zg_20to25->GetYaxis()->SetTitleSize(0.05);
    h3zg_25to30 = new TH2F("h3zg_25to30","g rec gen theta 25to30",1000,0,3.2,1000,0,3.2);
    h3zg_25to30->GetXaxis()->SetTitle("Gen theta"); h3zg_25to30->GetYaxis()->SetTitle("Rec theta");
    h3zg_25to30->GetXaxis()->SetLabelSize(0.05);h3zg_25to30->GetYaxis()->SetLabelSize(0.05);
    h3zg_25to30->GetXaxis()->SetTitleSize(0.05);h3zg_25to30->GetYaxis()->SetTitleSize(0.05);
    h3zg_30to35 = new TH2F("h3zg_30to35","g rec gen theta 30to35",1000,0,3.2,1000,0,3.2);
    h3zg_30to35->GetXaxis()->SetTitle("Gen theta"); h3zg_30to35->GetYaxis()->SetTitle("Rec theta");
    h3zg_30to35->GetXaxis()->SetLabelSize(0.05);h3zg_30to35->GetYaxis()->SetLabelSize(0.05);
    h3zg_30to35->GetXaxis()->SetTitleSize(0.05);h3zg_30to35->GetYaxis()->SetTitleSize(0.05);
    h3zg_35to40 = new TH2F("h3zg_35to40","g rec gen theta 35to40",1000,0,3.2,1000,0,3.2);
    h3zg_35to40->GetXaxis()->SetTitle("Gen theta"); h3zg_35to40->GetYaxis()->SetTitle("Rec theta");
    h3zg_35to40->GetXaxis()->SetLabelSize(0.05);h3zg_35to40->GetYaxis()->SetLabelSize(0.05);
    h3zg_35to40->GetXaxis()->SetTitleSize(0.05);h3zg_35to40->GetYaxis()->SetTitleSize(0.05);
    h3zg_40to45 = new TH2F("h3zg_40to45","g rec gen theta 40to45",1000,0,3.2,1000,0,3.2);
    h3zg_40to45->GetXaxis()->SetTitle("Gen theta"); h3zg_40to45->GetYaxis()->SetTitle("Rec theta");
    h3zg_40to45->GetXaxis()->SetLabelSize(0.05);h3zg_40to45->GetYaxis()->SetLabelSize(0.05);
    h3zg_40to45->GetXaxis()->SetTitleSize(0.05);h3zg_40to45->GetYaxis()->SetTitleSize(0.05);
    h3zg_45to50 = new TH2F("h3zg_45to50","g rec gen theta 45to50",1000,0,3.2,1000,0,3.2);
    h3zg_45to50->GetXaxis()->SetTitle("Gen theta"); h3zg_45to50->GetYaxis()->SetTitle("Rec theta");
    h3zg_45to50->GetXaxis()->SetLabelSize(0.05);h3zg_45to50->GetYaxis()->SetLabelSize(0.05);
    h3zg_45to50->GetXaxis()->SetTitleSize(0.05);h3zg_45to50->GetYaxis()->SetTitleSize(0.05);
    h3zg_50to55 = new TH2F("h3zg_50to55","g rec gen theta 50to55",1000,0,3.2,1000,0,3.2);
    h3zg_50to55->GetXaxis()->SetTitle("Gen theta"); h3zg_50to55->GetYaxis()->SetTitle("Rec theta");
    h3zg_50to55->GetXaxis()->SetLabelSize(0.05);h3zg_50to55->GetYaxis()->SetLabelSize(0.05);
    h3zg_50to55->GetXaxis()->SetTitleSize(0.05);h3zg_50to55->GetYaxis()->SetTitleSize(0.05);
    h3zg_55to60 = new TH2F("h3zg_55to60","g rec gen theta 55to60",1000,0,3.2,1000,0,3.2);
    h3zg_55to60->GetXaxis()->SetTitle("Gen theta"); h3zg_55to60->GetYaxis()->SetTitle("Rec theta");
    h3zg_55to60->GetXaxis()->SetLabelSize(0.05);h3zg_55to60->GetYaxis()->SetLabelSize(0.05);
    h3zg_55to60->GetXaxis()->SetTitleSize(0.05);h3zg_55to60->GetYaxis()->SetTitleSize(0.05);
    
   
    h1zw_5to10 = new TH2F("h1zw_5to10","w rec gen p",5,5,10,5,5,10);
    h1zw_5to10->GetXaxis()->SetTitle("Gen p"); h1zw_5to10->GetYaxis()->SetTitle("Rec p");
    h1zw_5to10->GetXaxis()->SetLabelSize(0.05);h1zw_5to10->GetYaxis()->SetLabelSize(0.05);
    h1zw_5to10->GetXaxis()->SetTitleSize(0.05);h1zw_5to10->GetYaxis()->SetTitleSize(0.05);
    h1zw_10to15 = new TH2F("h1zw_10to15","w rec gen p",5,10,15,5,10,15);
    h1zw_10to15->GetXaxis()->SetTitle("Gen p"); h1zw_10to15->GetYaxis()->SetTitle("Rec p");
    h1zw_10to15->GetXaxis()->SetLabelSize(0.05);h1zw_10to15->GetYaxis()->SetLabelSize(0.05);
    h1zw_10to15->GetXaxis()->SetTitleSize(0.05);h1zw_10to15->GetYaxis()->SetTitleSize(0.05);
    h1zw_15to20 = new TH2F("h1zw_15to20","w rec gen p",5,15,20,5,15,20);
    h1zw_15to20->GetXaxis()->SetTitle("Gen p"); h1zw_15to20->GetYaxis()->SetTitle("Rec p");
    h1zw_15to20->GetXaxis()->SetLabelSize(0.05);h1zw_15to20->GetYaxis()->SetLabelSize(0.05);
    h1zw_15to20->GetXaxis()->SetTitleSize(0.05);h1zw_15to20->GetYaxis()->SetTitleSize(0.05);
    h1zw_20to25 = new TH2F("h1zw_20to25","w rec gen p",5,20,25,5,20,25);
    h1zw_20to25->GetXaxis()->SetTitle("Gen p"); h1zw_20to25->GetYaxis()->SetTitle("Rec p");
    h1zw_20to25->GetXaxis()->SetLabelSize(0.05);h1zw_20to25->GetYaxis()->SetLabelSize(0.05);
    h1zw_20to25->GetXaxis()->SetTitleSize(0.05);h1zw_20to25->GetYaxis()->SetTitleSize(0.05);
    h1zw_25to30 = new TH2F("h1zw_25to30","w rec gen p",5,25,30,5,25,30);
    h1zw_25to30->GetXaxis()->SetTitle("Gen p"); h1zw_25to30->GetYaxis()->SetTitle("Rec p");
    h1zw_25to30->GetXaxis()->SetLabelSize(0.05);h1zw_25to30->GetYaxis()->SetLabelSize(0.05);
    h1zw_25to30->GetXaxis()->SetTitleSize(0.05);h1zw_25to30->GetYaxis()->SetTitleSize(0.05);
    h1zw_30to35 = new TH2F("h1zw_30to35","w rec gen p",5,30,35,5,30,35);
    h1zw_30to35->GetXaxis()->SetTitle("Gen p"); h1zw_30to35->GetYaxis()->SetTitle("Rec p");
    h1zw_30to35->GetXaxis()->SetLabelSize(0.05);h1zw_30to35->GetYaxis()->SetLabelSize(0.05);
    h1zw_30to35->GetXaxis()->SetTitleSize(0.05);h1zw_30to35->GetYaxis()->SetTitleSize(0.05);
    h1zw_35to40 = new TH2F("h1zw_35to40","w rec gen p",5,35,40,5,35,40);
    h1zw_35to40->GetXaxis()->SetTitle("Gen p"); h1zw_35to40->GetYaxis()->SetTitle("Rec p");
    h1zw_35to40->GetXaxis()->SetLabelSize(0.05);h1zw_35to40->GetYaxis()->SetLabelSize(0.05);
    h1zw_30to35->GetXaxis()->SetTitleSize(0.05);h1zw_30to35->GetYaxis()->SetTitleSize(0.05);
    h1zw_40to45 = new TH2F("h1zw_40to45","w rec gen p",5,40,45,5,40,45);
    h1zw_40to45->GetXaxis()->SetTitle("Gen p"); h1zw_40to45->GetYaxis()->SetTitle("Rec p");
    h1zw_40to45->GetXaxis()->SetLabelSize(0.05);h1zw_40to45->GetYaxis()->SetLabelSize(0.05);
    h1zw_40to45->GetXaxis()->SetTitleSize(0.05);h1zw_40to45->GetYaxis()->SetTitleSize(0.05);
    h1zw_45to50 = new TH2F("h1zw_45to50","w rec gen p",5,45,50,5,45,50);
    h1zw_45to50->GetXaxis()->SetTitle("Gen p"); h1zw_45to50->GetYaxis()->SetTitle("Rec p");
    h1zw_45to50->GetXaxis()->SetLabelSize(0.05);h1zw_45to50->GetYaxis()->SetLabelSize(0.05);
    h1zw_45to50->GetXaxis()->SetTitleSize(0.05);h1zw_45to50->GetYaxis()->SetTitleSize(0.05);
    h1zw_50to55 = new TH2F("h1zw_50to55","w rec gen p",5,50,55,5,50,55);
    h1zw_50to55->GetXaxis()->SetTitle("Gen p"); h1zw_50to55->GetYaxis()->SetTitle("Rec p");
    h1zw_50to55->GetXaxis()->SetLabelSize(0.05);h1zw_50to55->GetYaxis()->SetLabelSize(0.05);
    h1zw_50to55->GetXaxis()->SetTitleSize(0.05);h1zw_50to55->GetYaxis()->SetTitleSize(0.05);
    h1zw_55to60 = new TH2F("h1zw_55to60","w rec gen p",5,55,60,5,55,60);
    h1zw_55to60->GetXaxis()->SetTitle("Gen p"); h1zw_55to60->GetYaxis()->SetTitle("Rec p");
    h1zw_55to60->GetXaxis()->SetLabelSize(0.05);h1zw_55to60->GetYaxis()->SetLabelSize(0.05);
    h1zw_55to60->GetXaxis()->SetTitleSize(0.05);h1zw_55to60->GetYaxis()->SetTitleSize(0.05);
    
    
    h2zw_5to10 = new TH2F("h2zw_5to10","w rec gen phi 5to10",1000,0,3.2,1000,0,3.2);
    h2zw_5to10->GetXaxis()->SetTitle("Gen phi"); h2zw_5to10->GetYaxis()->SetTitle("Rec phi");
    h2zw_5to10->GetXaxis()->SetLabelSize(0.05);h2zw_5to10->GetYaxis()->SetLabelSize(0.05);
    h2zw_5to10->GetXaxis()->SetTitleSize(0.05);h2zw_5to10->GetYaxis()->SetTitleSize(0.05);
    h2zw_10to15 = new TH2F("h2zw_10to15","w rec gen phi 10to15",1000,0,3.2,1000,0,3.2);
    h2zw_10to15->GetXaxis()->SetTitle("Gen phi"); h2zw_10to15->GetYaxis()->SetTitle("Rec phi");
    h2zw_10to15->GetXaxis()->SetLabelSize(0.05);h2zw_10to15->GetYaxis()->SetLabelSize(0.05);
    h2zw_10to15->GetXaxis()->SetTitleSize(0.05);h2zw_10to15->GetYaxis()->SetTitleSize(0.05);
    h2zw_15to20 = new TH2F("h2zw_15to20","w rec gen phi 15to20",1000,0,3.2,1000,0,3.2);
    h2zw_15to20->GetXaxis()->SetTitle("Gen phi"); h2zw_15to20->GetYaxis()->SetTitle("Rec phi");
    h2zw_15to20->GetXaxis()->SetLabelSize(0.05);h2zw_15to20->GetYaxis()->SetLabelSize(0.05);
    h2zw_15to20->GetXaxis()->SetTitleSize(0.05);h2zw_15to20->GetYaxis()->SetTitleSize(0.05);
    h2zw_20to25 = new TH2F("h2zw_20to25","w rec gen phi 20to25",1000,0,3.2,1000,0,3.2);
    h2zw_20to25->GetXaxis()->SetTitle("Gen phi"); h2zw_20to25->GetYaxis()->SetTitle("Rec phi");
    h2zw_20to25->GetXaxis()->SetLabelSize(0.05);h2zw_20to25->GetYaxis()->SetLabelSize(0.05);
    h2zw_20to25->GetXaxis()->SetTitleSize(0.05);h2zw_20to25->GetYaxis()->SetTitleSize(0.05);
    h2zw_25to30 = new TH2F("h2zw_25to30","w rec gen phi 25to30",1000,0,3.2,1000,0,3.2);
    h2zw_25to30->GetXaxis()->SetTitle("Gen phi"); h2zw_25to30->GetYaxis()->SetTitle("Rec phi");
    h2zw_25to30->GetXaxis()->SetLabelSize(0.05);h2zw_25to30->GetYaxis()->SetLabelSize(0.05);
    h2zw_25to30->GetXaxis()->SetTitleSize(0.05);h2zw_25to30->GetYaxis()->SetTitleSize(0.05);
    h2zw_30to35 = new TH2F("h2zw_30to35","w rec gen phi 30to35",1000,0,3.2,1000,0,3.2);
    h2zw_30to35->GetXaxis()->SetTitle("Gen phi"); h2zw_30to35->GetYaxis()->SetTitle("Rec phi");
    h2zw_30to35->GetXaxis()->SetLabelSize(0.05); h2zw_30to35->GetYaxis()->SetLabelSize(0.05);
    h2zw_30to35->GetXaxis()->SetTitleSize(0.05);h2zw_30to35->GetYaxis()->SetTitleSize(0.05);
    h2zw_35to40 = new TH2F("h2zw_35to40","w rec gen phi 35to40",1000,0,3.2,1000,0,3.2);
    h2zw_35to40->GetXaxis()->SetTitle("Gen phi"); h2zw_35to40->GetYaxis()->SetTitle("Rec phi");
    h2zw_35to40->GetXaxis()->SetLabelSize(0.05);h2zw_35to40->GetYaxis()->SetLabelSize(0.05);
    h2zw_35to40->GetXaxis()->SetTitleSize(0.05);h2zw_35to40->GetYaxis()->SetTitleSize(0.05);
    h2zw_40to45 = new TH2F("h2zw_40to45","w rec gen phi 40to45",1000,0,3.2,1000,0,3.2);
    h2zw_40to45->GetXaxis()->SetTitle("Gen phi"); h2zw_40to45->GetYaxis()->SetTitle("Rec phi");
    h2zw_40to45->GetXaxis()->SetLabelSize(0.05);h2zw_40to45->GetYaxis()->SetLabelSize(0.05);
    h2zw_40to45->GetXaxis()->SetTitleSize(0.05);h2zw_40to45->GetYaxis()->SetTitleSize(0.05);
    h2zw_45to50 = new TH2F("h2zw_45to50","w rec gen phi 45to50",1000,0,3.2,1000,0,3.2);
    h2zw_45to50->GetXaxis()->SetTitle("Gen phi"); h2zw_45to50->GetYaxis()->SetTitle("Rec phi");
    h2zw_45to50->GetXaxis()->SetLabelSize(0.05);h2zw_45to50->GetYaxis()->SetLabelSize(0.05);
    h2zw_45to50->GetXaxis()->SetTitleSize(0.05);h2zw_45to50->GetYaxis()->SetTitleSize(0.05);
    h2zw_50to55 = new TH2F("h2zw_50to55","w rec gen phi 50to55",1000,0,3.2,1000,0,3.2);
    h2zw_50to55->GetXaxis()->SetTitle("Gen phi"); h2zw_50to55->GetYaxis()->SetTitle("Rec phi");
    h2zw_50to55->GetXaxis()->SetLabelSize(0.05);h2zw_50to55->GetYaxis()->SetLabelSize(0.05);
    h2zw_50to55->GetXaxis()->SetTitleSize(0.05);h2zw_50to55->GetYaxis()->SetTitleSize(0.05);
    h2zw_55to60 = new TH2F("h2zw_55to60","w rec gen phi 55to60",1000,0,3.2,1000,0,3.2);
    h2zw_55to60->GetXaxis()->SetTitle("Gen phi"); h2zw_55to60->GetYaxis()->SetTitle("Rec phi");
    h2zw_55to60->GetXaxis()->SetLabelSize(0.05);h2zw_55to60->GetYaxis()->SetLabelSize(0.05);
    h2zw_55to60->GetXaxis()->SetTitleSize(0.05);h2zw_55to60->GetYaxis()->SetTitleSize(0.05);
    
    
    h3zw_5to10 = new TH2F("h3zw_5to10","w rec gen theta 5to10",1000,0,3.2,1000,0,3.2);
    h3zw_5to10->GetXaxis()->SetTitle("Gen theta"); h3zw_5to10->GetYaxis()->SetTitle("Rec theta");
    h3zw_5to10->GetXaxis()->SetLabelSize(0.05);h3zw_5to10->GetYaxis()->SetLabelSize(0.05);
    h3zw_5to10->GetXaxis()->SetTitleSize(0.05);h3zw_5to10->GetYaxis()->SetTitleSize(0.05);
    h3zw_10to15 = new TH2F("h3zw_10to15","w rec gen theta 10to15",1000,0,3.2,1000,0,3.2);
    h3zw_10to15->GetXaxis()->SetTitle("Gen theta"); h3zw_10to15->GetYaxis()->SetTitle("Rec theta");
    h3zw_10to15->GetXaxis()->SetLabelSize(0.05);h3zw_10to15->GetYaxis()->SetLabelSize(0.05);
    h3zw_10to15->GetXaxis()->SetTitleSize(0.05);h3zw_10to15->GetYaxis()->SetTitleSize(0.05);
    h3zw_15to20 = new TH2F("h3zw_15to20","w rec gen theta 15to20",1000,0,3.2,1000,0,3.2);
    h3zw_15to20->GetXaxis()->SetTitle("Gen theta"); h3zw_15to20->GetYaxis()->SetTitle("Rec theta");
    h3zw_15to20->GetXaxis()->SetLabelSize(0.05);h3zw_15to20->GetYaxis()->SetLabelSize(0.05);
    h3zw_15to20->GetXaxis()->SetTitleSize(0.05);h3zw_15to20->GetYaxis()->SetTitleSize(0.05);
    h3zw_20to25 = new TH2F("h3zw_20to25","w rec gen theta 20to25",1000,0,3.2,1000,0,3.2);
    h3zw_20to25->GetXaxis()->SetTitle("Gen theta"); h3zw_20to25->GetYaxis()->SetTitle("Rec theta");
    h3zw_20to25->GetXaxis()->SetLabelSize(0.05); h3zw_20to25->GetYaxis()->SetLabelSize(0.05);
    h3zw_20to25->GetXaxis()->SetTitleSize(0.05); h3zw_20to25->GetYaxis()->SetTitleSize(0.05);
    h3zw_25to30 = new TH2F("h3zw_25to30","w rec gen theta 25to30",1000,0,3.2,1000,0,3.2);
    h3zw_25to30->GetXaxis()->SetTitle("Gen theta"); h3zw_25to30->GetYaxis()->SetTitle("Rec theta");
    h3zw_25to30->GetXaxis()->SetLabelSize(0.05);h3zw_25to30->GetYaxis()->SetLabelSize(0.05);
    h3zw_25to30->GetXaxis()->SetTitleSize(0.05);h3zw_25to30->GetYaxis()->SetTitleSize(0.05);
    h3zw_30to35 = new TH2F("h3zw_30to35","w rec gen theta 30to35",1000,0,3.2,1000,0,3.2);
    h3zw_30to35->GetXaxis()->SetTitle("Gen theta"); h3zw_30to35->GetYaxis()->SetTitle("Rec theta");
    h3zw_30to35->GetXaxis()->SetLabelSize(0.05);h3zw_30to35->GetYaxis()->SetLabelSize(0.05);
    h3zw_30to35->GetXaxis()->SetTitleSize(0.05);h3zw_30to35->GetYaxis()->SetTitleSize(0.05);
    h3zw_35to40 = new TH2F("h3zw_35to40","w rec gen theta 35to40",1000,0,3.2,1000,0,3.2);
    h3zw_35to40->GetXaxis()->SetTitle("Gen theta"); h3zw_35to40->GetYaxis()->SetTitle("Rec theta");
    h3zw_35to40->GetXaxis()->SetLabelSize(0.05);h3zw_35to40->GetYaxis()->SetLabelSize(0.05);
    h3zw_35to40->GetXaxis()->SetTitleSize(0.05);h3zw_35to40->GetYaxis()->SetTitleSize(0.05);
    h3zw_40to45 = new TH2F("h3zw_40to45","w rec gen theta 40to45",1000,0,3.2,1000,0,3.2);
    h3zw_40to45->GetXaxis()->SetTitle("Gen theta"); h3zw_40to45->GetYaxis()->SetTitle("Rec theta");
    h3zw_40to45->GetXaxis()->SetLabelSize(0.05);h3zw_40to45->GetYaxis()->SetLabelSize(0.05);
    h3zw_40to45->GetXaxis()->SetTitleSize(0.05);h3zw_40to45->GetYaxis()->SetTitleSize(0.05);
    h3zw_45to50 = new TH2F("h3zw_45to50","w rec gen theta 45to50",1000,0,3.2,1000,0,3.2);
    h3zw_45to50->GetXaxis()->SetTitle("Gen theta"); h3zw_45to50->GetYaxis()->SetTitle("Rec theta");
    h3zw_45to50->GetXaxis()->SetLabelSize(0.05);h3zw_45to50->GetYaxis()->SetLabelSize(0.05);
    h3zw_45to50->GetXaxis()->SetTitleSize(0.05);h3zw_45to50->GetYaxis()->SetTitleSize(0.05);
    h3zw_50to55 = new TH2F("h3zw_50to55","w rec gen theta 50to55",1000,0,3.2,1000,0,3.2);
    h3zw_50to55->GetXaxis()->SetTitle("Gen theta"); h3zw_50to55->GetYaxis()->SetTitle("Rec theta");
    h3zw_50to55->GetXaxis()->SetLabelSize(0.05);h3zw_50to55->GetYaxis()->SetLabelSize(0.05);
    h3zw_50to55->GetXaxis()->SetTitleSize(0.05);h3zw_50to55->GetYaxis()->SetTitleSize(0.05);
    h3zw_55to60 = new TH2F("h3zw_55to60","w rec gen theta 55to60",1000,0,3.2,1000,0,3.2);
    h3zw_55to60->GetXaxis()->SetTitle("Gen theta"); h3zw_55to60->GetYaxis()->SetTitle("Rec theta");
    h3zw_55to60->GetXaxis()->SetLabelSize(0.05);h3zw_55to60->GetYaxis()->SetLabelSize(0.05);
    h3zw_55to60->GetXaxis()->SetTitleSize(0.05);h3zw_55to60->GetYaxis()->SetTitleSize(0.05);
    
    
    h2a = new TH1F("h2a","rec gen E scheme Jt Phi",100,-3.5,3.5);
    h2a->SetLineColor(kBlue);
    h2b = new TH1F("h2b","rec gen WTA Jt phi",100,-3.5,3.5);
    h2b->SetLineColor(kBlue);
     h2c = new TH1F("h2c","rec gen groomed Jt phi",100,-3.5,3.5);
    h2c->SetLineColor(kBlue);
     h2d = new TH1F("h2d","rec gen E scheme Jt Phi",100,-3.5,3.5);
    h2d->SetLineColor(kRed);
    h2e = new TH1F("h2e","rec gen WTA Jt phi",100,-3.5,3.5);
    h2e->SetLineColor(kRed);
     h2f = new TH1F("h2f","rec gen groomed Jt phi",100,-3.5,3.5);
    h2f->SetLineColor(kRed);
     
     h3a = new TH1F("h3a","rec gen E scheme Jt theta",100,0,3.3);
    h3a->SetLineColor(kBlue);
   h3b = new TH1F("h3b","rec gen WTA Jt tehta",100,0,3.3);
    h3b->SetLineColor(kBlue);
   h3c = new TH1F("h3c","rec gen groomed Jt theta",100,0,3.3);
    h3c->SetLineColor(kBlue);
    h3d = new TH1F("h3d","rec gen E scheme Jt theta",100,0,3.3);
    h3d->SetLineColor(kRed);
   h3e = new TH1F("h3e","rec gen WTA Jt tehta",100,0,3.3);
    h3e->SetLineColor(kRed);
   h3f = new TH1F("h3f","rec gen groomed Jt theta",100,0,3.3);
    h3f->SetLineColor(kRed);
   
    p_vs_theta =  new TH2F("p_vs_theta","p vs theta", 100,0,3.3, 60,0,60);
    
   h4 = new TH1F("h4","rec E pt",100,-50,50);
    h4b = new TH1F("h4b","gen E pt",100,-50,50);
    
    h5 = new TH1F("h5","rec E phi",100,-4,4);
     h5b = new TH1F("h5b","gen E phi",100,-4,4);
    
    
    
    
    h6_5to10 = new TH1F("h6_5to10","rec, gen del_R_E_vs_g_5to10",100,-0.03,0.2);
    h6_5to10->SetLineColor(kBlue);
    //h6_5to10->GetYaxis()->SetTitle("Probability of R"); h6_5to10->GetXaxis()->SetTitle("R");
    h6b_5to10 = new TH1F("h6b_5to10","rec, gen del_R_E_vs_g_5to10",100,-0.03,0.2);
    h6b_5to10->SetLineColor(kRed);
    //h6b_5to10->GetYaxis()->SetTitle("Probability of R"); h6b_5to10->GetXaxis()->SetTitle("R");
    h6z_5to10 = new TH2F("h6z_5to10","rec, gen del_R_E_vs_g_5to10",100,-0.03,0.4,100,-0.03,0.4);
   // h6_5to10->GetYaxis()->SetTitle("gen R"); h6_5to10->GetXaxis()->SetTitle("rec R");
    
    h6_10to15 = new TH1F("h6_10to15","rec, gen del_R_E_vs_g_10to15",100,-0.03,0.2);
    h6_10to15->SetLineColor(kBlue);
    //h6_10to15->GetYaxis()->SetTitle("Probability of R"); h6_10to15->GetXaxis()->SetTitle("R");
    h6b_10to15 = new TH1F("h6b_10to15","rec, gen del_R_E_vs_g_10to15",100,-0.03,0.2);
    h6b_10to15->SetLineColor(kRed);
    //h6b_10to15->GetYaxis()->SetTitle("Probability of R"); h6b_10to15->GetXaxis()->SetTitle("R");
    h6z_10to15 = new TH2F("hz6_10to15","rec, gen del_R_E_vs_g_10to15",100,-0.03,0.4,100,-0.03,0.4);
    
    h6_15to20 = new TH1F("h6_15to20","rec, gen del_R_E_vs_g_15to20",100,-0.03,0.2);
    h6_15to20->SetLineColor(kBlue);
    //h6_15to20->GetYaxis()->SetTitle("Probability of R"); h6_15to20->GetXaxis()->SetTitle("R");
    h6b_15to20 = new TH1F("h6b_15to20","rec, gen del_R_E_vs_g_15to20",100,-0.03,0.2);
    h6b_15to20->SetLineColor(kRed);
    //h6b_15to20->GetYaxis()->SetTitle("Probability of R"); h6b_15to20->GetXaxis()->SetTitle("R");
    h6z_15to20 = new TH2F("h6z_15to20","rec, gen del_R_E_vs_g_15to20",100,-0.03,0.4,100,-0.03,0.4);
    
    h6_20to25 = new TH1F("h6_20to25","rec, gen del_R_E_vs_g_20to25",100,-0.03,0.2);
    h6_20to25->SetLineColor(kBlue);
    //h6_20to25->GetYaxis()->SetTitle("Probability of R"); h6_20to25->GetXaxis()->SetTitle("R");
    h6b_20to25 = new TH1F("h6b_20to25","rec, gen del_R_E_vs_g_20to25",100,-0.03,0.2);
   h6b_20to25->SetLineColor(kRed);
    //h6b_20to25->GetYaxis()->SetTitle("Probability of R"); h6b_20to25->GetXaxis()->SetTitle("R");
    h6z_20to25 = new TH2F("h6z_20to25","rec, gen del_R_E_vs_g_20to25",100,-0.03,0.4,100,-0.03,0.4);
    
    h6_25to30 = new TH1F("h6_25to30","rec, gen del_R_E_vs_g_25to30",100,-0.03,0.2);
    h6_25to30->SetLineColor(kBlue);
    //h6_25to30->GetYaxis()->SetTitle("Probability of R"); h6_25to30->GetXaxis()->SetTitle("R");
    h6b_25to30 = new TH1F("h6b_25to30","rec, gen del_R_E_vs_g_25to30",100,-0.03,0.2);
   h6b_25to30->SetLineColor(kRed);
    //h6b_25to30->GetYaxis()->SetTitle("Probability of R"); h6b_25to30->GetXaxis()->SetTitle("R");
    h6z_25to30 = new TH2F("hz6_25to30","rec, gen del_R_E_vs_g_25to30",100,-0.03,0.4,100,-0.03,0.4);
    
    h6_30to35 = new TH1F("h6_30to35","rec, gen del_R_E_vs_g_30to35",100,-0.03,0.2);
    h6_30to35->SetLineColor(kBlue);
    //h6_30to35->GetYaxis()->SetTitle("Probability of R"); h6_30to35->GetXaxis()->SetTitle("R");
    h6b_30to35 = new TH1F("h6b_30to35","rec, gen del_R_E_vs_g_30to35",100,-0.03,0.2);
    h6b_30to35->SetLineColor(kRed);
    //h6b_30to35->GetYaxis()->SetTitle("Probability of R"); h6b_30to35->GetXaxis()->SetTitle("R");
    h6z_30to35 = new TH2F("h6z_30to35","rec, gen del_R_E_vs_g_30to35",100,-0.03,0.4,100,-0.03,0.4);
    
    h6_35to40 = new TH1F("h6_35to40","rec, gen del_R_E_vs_g_35to40",100,-0.03,0.2);
    h6_35to40->SetLineColor(kBlue);
    //h6_35to40->GetYaxis()->SetTitle("Probability of R"); h6_35to40->GetXaxis()->SetTitle("R");
    h6b_35to40 = new TH1F("h6b_35to40","rec, gen del_R_E_vs_g_35to40",100,-0.03,0.2);
    h6b_35to40->SetLineColor(kRed);
    //h6b_35to40->GetYaxis()->SetTitle("Probability of R"); h6b_35to40->GetXaxis()->SetTitle("R");
    h6z_35to40 = new TH2F("h6z_35to40","rec, gen del_R_E_vs_g_35to40",100,-0.03,0.4,100,-0.03,0.4);
    
    h6_40to45 = new TH1F("h6_40to45","rec, gen del_R_E_vs_g_40to45",100,-0.03,0.2);
    h6_40to45->SetLineColor(kBlue);
    //h6_40to45->GetYaxis()->SetTitle("Probability of R"); h6_40to45->GetXaxis()->SetTitle("R");
    h6b_40to45 = new TH1F("h6b_40to45","rec, gen del_R_E_vs_g_40to45",100,-0.03,0.2);
    h6b_40to45->SetLineColor(kRed);
    //h6b_40to45->GetYaxis()->SetTitle("Probability of R"); h6b_40to45->GetXaxis()->SetTitle("R");
    h6z_40to45 = new TH2F("h6z_40to45","rec, gen del_R_E_vs_g_40to45",100,-0.03,0.2,100,-0.03,0.2);
    
    h6_45to50 = new TH1F("h6_45to50","rec, gen del_R_E_vs_g_45to50",100,-0.03,0.2);
    h6_45to50->SetLineColor(kBlue);
    //h6_45to50->GetYaxis()->SetTitle("Probability of R"); h6_45to50->GetXaxis()->SetTitle("R");
    h6b_45to50 = new TH1F("h6b_45to50","rec, gen del_R_E_vs_g_45to50",100,-0.03,0.2);
    h6b_45to50->SetLineColor(kRed);
    //h6b_45to50->GetYaxis()->SetTitle("Probability of R"); h6b_45to50->GetXaxis()->SetTitle("R");
    h6z_45to50 = new TH2F("h6z_45to50","rec, gen del_R_E_vs_g_45to50",100,-0.03,0.2,100,-0.03,0.2);
    
    h6_50to55 = new TH1F("h6_50to55","rec, gen del_R_E_vs_g_50to55",100,-0.03,0.2);
    h6_50to55->SetLineColor(kBlue);
    //h6_50to55->GetYaxis()->SetTitle("Probability of R"); h6_50to55->GetXaxis()->SetTitle("R");
    h6b_50to55 = new TH1F("h6b_50to55","rec, gen del_R_E_vs_g_50to55",100,-0.03,0.2);
    h6b_50to55->SetLineColor(kRed);
    //h6b_50to55->GetYaxis()->SetTitle("Probability of R"); h6b_50to55->GetXaxis()->SetTitle("R");
    h6z_50to55 = new TH2F("h6z_50to55","rec, gen del_R_E_vs_g_50to55",100,-0.03,0.2,100,-0.03,0.2);
    
    h6_55to60 = new TH1F("h6_55to60","rec, gen del_R_E_vs_g_55to60",100,-0.03,0.2);
    h6_55to60->SetLineColor(kBlue);
    //h6_55to60->GetYaxis()->SetTitle("Probability of R"); h6_55to60->GetXaxis()->SetTitle("R");
    h6b_55to60 = new TH1F("h6b_55to60","rec, gen del_R_E_vs_g_55to60",100,-0.03,0.2);
    h6b_55to60->SetLineColor(kRed); 
    //h6b_55to60->GetYaxis()->SetTitle("Probability of R");  h6b_55to60->GetXaxis()->SetTitle("R");
    h6z_55to60 = new TH2F("hz6_55to60","rec, gen del_R_E_vs_g_55to60",100,-0.03,0.2,100,-0.03,0.2);
    
    //h7 = new TH1F("h7","rec, gen del_R_E_vs_wta",100,-0.03,0.45);
   // h7->SetLineColor(kBlue);
  //  h7b = new TH1F("h7b","rec, gen del_R_E_vs_wta",100,-0.03,0.45);
 //   h7b->SetLineColor(kRed);
   // del_R_gen_rec_E_W = new TH1F(" del_R_gen_rec_E_W "," del_R_gen_rec_E_W ",100,-0.5,0.5 );
    
    h7_5to10 = new TH1F("h7_5to10","rec, gen del_R_E_vs_wta_5to10",100,-0.03,0.45);
    h7_5to10->SetLineColor(kBlue);
    //h7_5to10->GetYaxis()->SetTitle("Probability of R"); h7_5to10->GetXaxis()->SetTitle("R");
    h7b_5to10 = new TH1F("h7b_5to10","rec, gen del_R_E_vs_wta_5to10",100,-0.03,0.45);
    h7b_5to10->SetLineColor(kRed); 
    //h7b_5to10->GetYaxis()->SetTitle("Probability of R");  h7b_5to10->GetXaxis()->SetTitle("R");
    h7z_5to10 = new TH2F("h7z_5to10","rec, gen del_R_E_vs_wta_5to10",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_10to15 = new TH1F("h7_10to15","rec, gen del_R_E_vs_wta_10to15",100,-0.03,0.45);
    h7_10to15->SetLineColor(kBlue);
    //h7_10to15->GetYaxis()->SetTitle("Probability of R"); h7_10to15->GetXaxis()->SetTitle("R");
    h7b_10to15 = new TH1F("h7b_10to15","rec, gen del_R_E_vs_wta_10to15",100,-0.03,0.45);
    h7b_10to15->SetLineColor(kRed);
    //h7b_10to15->GetYaxis()->SetTitle("Probability of R"); h7b_10to15->GetXaxis()->SetTitle("R");
    h7z_10to15 = new TH2F("h7z_10to15","rec, gen del_R_E_vs_wta_10to15",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_15to20 = new TH1F("h7_15to20","rec, gen del_R_E_vs_wta_15to20",100,-0.03,0.45);
    h7_15to20->SetLineColor(kBlue);
    //h7_15to20->GetYaxis()->SetTitle("Probability of R"); h7_15to20->GetXaxis()->SetTitle("R");
    h7b_15to20 = new TH1F("h7b_15to20","rec, gen del_R_E_vs_wta_15to20",100,-0.03,0.45);
    h7b_15to20->SetLineColor(kRed);
    //h7b_15to20->GetYaxis()->SetTitle("Probability of R"); h7b_15to20->GetXaxis()->SetTitle("R");
    h7z_15to20 = new TH2F("h7z_15to20","rec, gen del_R_E_vs_wta_15to20",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_20to25 = new TH1F("h7_20to25","rec, gen del_R_E_vs_wta_20to25",100,-0.03,0.45);
    h7b_20to25->SetLineColor(kBlue);
    //h6_15to20->GetYaxis()->SetTitle("Probability of R"); h7b_20to25->GetXaxis()->SetTitle("R");
    h7b_20to25 = new TH1F("h7b_20to25","rec, gen del_R_E_vs_wta_20to25",100,-0.03,0.45);
    h7b_20to25->SetLineColor(kRed);
    //h7b_20to25->GetYaxis()->SetTitle("Probability of R"); h7b_20to25->GetXaxis()->SetTitle("R");
    h7z_20to25 = new TH2F("h7z_20to25","rec, gen del_R_E_vs_wta_20to25",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_25to30 = new TH1F("h7_25to30","rec, gen del_R_E_vs_wta_25to30",100,-0.03,0.45);
    h7_25to30->SetLineColor(kBlue);
    //h7_25to30->GetYaxis()->SetTitle("Probability of R"); h7_25to30->GetXaxis()->SetTitle("R");
    h7b_25to30 = new TH1F("h7b_25to30","rec, gen del_R_E_vs_wta_25to30",100,-0.03,0.45);
    h7b_25to30->SetLineColor(kRed);
    //h7b_25to30->GetYaxis()->SetTitle("Probability of R"); h7b_25to30->GetXaxis()->SetTitle("R");
    h7z_25to30 = new TH2F("h7z_25to30","rec, gen del_R_E_vs_wta_25to30",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_30to35 = new TH1F("h7_30to35","rec, gen del_R_E_vs_wta_30to35",100,-0.03,0.45);
    h7_30to35->SetLineColor(kBlue);
    //h7_30to35->GetYaxis()->SetTitle("Probability of R"); h7_30to35->GetXaxis()->SetTitle("R");
    h7b_30to35 = new TH1F("h7b_30to35","rec, gen del_R_E_vs_wta_30to35",100,-0.03,0.45);
    h7b_30to35->SetLineColor(kRed);
    //h7b_30to35->GetYaxis()->SetTitle("Probability of R"); h7b_30to35->GetXaxis()->SetTitle("R");
    h7z_30to35 = new TH2F("h7z_30to35","rec, gen del_R_E_vs_wta_30to35",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_35to40 = new TH1F("h7_35to40","rec, gen del_R_E_vs_wta_35to40",100,-0.03,0.45);
    h7_35to40->SetLineColor(kBlue);
    //h7_35to40->GetYaxis()->SetTitle("Probability of R"); h7_35to40->GetXaxis()->SetTitle("R");
    h7b_35to40 = new TH1F("h7b_35to40","rec, gen del_R_E_vs_wta_35to40",100,-0.03,0.45);
    h7b_35to40->SetLineColor(kRed);
    //h7b_35to40->GetYaxis()->SetTitle("Probability of R"); h7b_35to40->GetXaxis()->SetTitle("R");
    h7z_35to40 = new TH2F("h7z_35to40","rec, gen del_R_E_vs_wta_35to40",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_40to45 = new TH1F("h7_40to45","rec, gen del_R_E_vs_wta_40to45",100,-0.03,0.45);
    h7_40to45->SetLineColor(kBlue);
    //h7_40to45->GetYaxis()->SetTitle("Probability of R"); h7_40to45->GetXaxis()->SetTitle("R");
    h7b_40to45 = new TH1F("h7b_40to45","rec, gen del_R_E_vs_wta_40to45",100,-0.03,0.45);
    h7b_40to45->SetLineColor(kRed);
    //h7b_40to45->GetYaxis()->SetTitle("Probability of R"); h7b_40to45->GetXaxis()->SetTitle("R");
    h7z_40to45 = new TH2F("h7z_40to45","rec, gen del_R_E_vs_wta_40to45",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_45to50 = new TH1F("h7_45to50","rec, gen del_R_E_vs_wta_45to50",100,-0.03,0.45);
    h7_45to50->SetLineColor(kBlue);
    //h7_45to50->GetYaxis()->SetTitle("Probability of R"); h7_45to50->GetXaxis()->SetTitle("R");
    h7b_45to50 = new TH1F("h7b_45to50","rec, gen del_R_E_vs_wta_45to50",100,-0.03,0.45);
    h7b_45to50->SetLineColor(kRed);
    //h7b_45to50->GetYaxis()->SetTitle("Probability of R"); h7b_45to50->GetXaxis()->SetTitle("R");
    h7z_45to50 = new TH2F("hz7_45to50","rec, gen del_R_E_vs_wta_45to50",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_50to55 = new TH1F("h7_55to55","rec, gen del_R_E_vs_wta_50to55",100,-0.03,0.45);
    h7_50to55->SetLineColor(kBlue);
    //h7_50to55->GetYaxis()->SetTitle("Probability of R"); h7_50to55->GetXaxis()->SetTitle("R");
    h7b_50to55 = new TH1F("h7b_55to55","rec, gen del_R_E_vs_wta_50to55",100,-0.03,0.45);
    h7b_50to55->SetLineColor(kRed);
    //h7b_50to55->GetYaxis()->SetTitle("Probability of R"); h7b_50to55->GetXaxis()->SetTitle("R");
    h7z_50to55 = new TH2F("h7z_55to55","rec, gen del_R_E_vs_wta_50to55",100,-0.03,0.45,100,-0.03,0.45);
    
    h7_55to60 = new TH1F("h7_55to60","rec, gen del_R_E_vs_wta_55to60",100,-0.03,0.45);
    h7_55to60->SetLineColor(kBlue);
    //h7_55to60->GetYaxis()->SetTitle("Probability of R"); h7_55to60->GetXaxis()->SetTitle("R");
    h7b_55to60 = new TH1F("h7b_55to60","rec, gen del_R_E_vs_wta_55to60",100,-0.03,0.45);
    h7b_55to60->SetLineColor(kRed);
    //h7b_55to60->GetYaxis()->SetTitle("Probability of R"); h7b_55to60->GetXaxis()->SetTitle("R");
    h7z_55to60 = new TH2F("h7z_55to60","rec, gen del_R_E_vs_wta_55to60",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_5to10 = new TH1F("h8_5to10","rec, gen del_R_wta_vs_g_5to10",100,-0.03,0.45);
    h8_5to10->SetLineColor(kBlue);
    //h8_5to10->GetYaxis()->SetTitle("Probability of R"); h8_5to10->GetXaxis()->SetTitle("R");
    h8b_5to10 = new TH1F("h8b_5to10","rec, gen del_R_wta_vs_g_5to10",100,-0.03,0.45);
    h8b_5to10->SetLineColor(kRed);
    //h8b_5to10->GetYaxis()->SetTitle("Probability of R"); h8b_5to10->GetXaxis()->SetTitle("R");
    h8z_5to10 = new TH2F("h8z_5to10","rec, gen del_R_wta_vs_g_5to10",100,-0.03,0.45,100,-0.03,0.45);
 //   del_R_gen_rec_W_g = new TH1F(" del_R_gen_rec_W_g "," del_R_gen_rec_W_g ",100,-0.5,0.5 );
    
    h8_10to15 = new TH1F("h8_10to15","rec, gen del_R_wta_vs_g_10to15",100,-0.03,0.45);
    h8_10to15->SetLineColor(kBlue);
    //h8_10to15->GetYaxis()->SetTitle("Probability of R"); h8_10to15->GetXaxis()->SetTitle("R");
    h8b_10to15 = new TH1F("h8b_10to15","rec, gen del_R_wta_vs_g_10to15",100,-0.03,0.45);
    h8b_10to15->SetLineColor(kRed);
    //h8b_10to15->GetYaxis()->SetTitle("Probability of R"); h8b_10to15->GetXaxis()->SetTitle("R");
    h8z_10to15 = new TH2F("h8z_10to15","rec, gen del_R_wta_vs_g_10to15",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_15to20 = new TH1F("h8_15to20","rec, gen del_R_wta_vs_g_15to20",100,-0.03,0.45);
    h8_15to20->SetLineColor(kBlue);
    //h8_15to20->GetYaxis()->SetTitle("Probability of R"); h8_15to20->GetXaxis()->SetTitle("R");
    h8b_15to20 = new TH1F("h8b_15to20","rec, gen del_R_wta_vs_g_15to20",100,-0.03,0.45);
    h8b_15to20->SetLineColor(kRed);
    //h8b_15to20->GetYaxis()->SetTitle("Probability of R"); h8b_15to20->GetXaxis()->SetTitle("R");
    h8z_15to20 = new TH2F("h8z_15to20","rec, gen del_R_wta_vs_g_15to20",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_20to25 = new TH1F("h8_20to25","rec, gen del_R_wta_vs_g_20to25",100,-0.03,0.45);
    h8_20to25->SetLineColor(kBlue);
    //h8_20to25->GetYaxis()->SetTitle("Probability of R"); h8_20to25->GetXaxis()->SetTitle("R");
    h8b_20to25 = new TH1F("h8b_20to25","rec, gen del_R_wta_vs_g_20to25",100,-0.03,0.45);
    h8b_20to25->SetLineColor(kRed);
    //h8b_20to25->GetYaxis()->SetTitle("Probability of R"); h8b_20to25->GetXaxis()->SetTitle("R");
    h8z_20to25 = new TH2F("h8z_20to25","rec, gen del_R_wta_vs_g_20to25",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_25to30 = new TH1F("h8_25to30","rec, gen del_R_wta_vs_g_25to30",100,-0.03,0.45);
    h8_25to30->SetLineColor(kBlue);
    //h8_25to30->GetYaxis()->SetTitle("Probability of R"); h8_25to30->GetXaxis()->SetTitle("R");
    h8b_25to30 = new TH1F("h8b_25to30","rec, gen del_R_wta_vs_g_25to30",100,-0.03,0.45);
    h8b_25to30->SetLineColor(kRed);
    //h8b_25to30->GetYaxis()->SetTitle("Probability of R"); h8b_25to30->GetXaxis()->SetTitle("R");
    h8z_25to30 = new TH2F("h8z_25to30","rec, gen del_R_wta_vs_g_25to30",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_30to35 = new TH1F("h8_30to35","rec, gen del_R_wta_vs_g_30to35",100,-0.03,0.45);
    h8_30to35->SetLineColor(kBlue);
    //h8_30to35->GetYaxis()->SetTitle("Probability of R"); h8_30to35->GetXaxis()->SetTitle("R");
    h8b_30to35 = new TH1F("h8b_30to35","rec, gen del_R_wta_vs_g_30to35",100,-0.03,0.45);
    h8b_30to35->SetLineColor(kRed);
    //h8b_30to35->GetYaxis()->SetTitle("Probability of R"); h8b_30to35->GetXaxis()->SetTitle("R");
    h8z_30to35 = new TH2F("h8z_30to35","rec, gen del_R_wta_vs_g_30to35",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_35to40 = new TH1F("h8_35to40","rec, gen del_R_wta_vs_g_35to40",100,-0.03,0.45);
    h8_35to40->SetLineColor(kBlue);
    //h8_35to40->GetYaxis()->SetTitle("Probability of R"); h8_35to40->GetXaxis()->SetTitle("R");
    h8b_35to40 = new TH1F("h8b_35to40","rec, gen del_R_wta_vs_g_35to40",100,-0.03,0.45);
    h8b_35to40->SetLineColor(kRed);
    //h8b_35to40->GetYaxis()->SetTitle("Probability of R"); h8b_35to40->GetXaxis()->SetTitle("R");
    h8z_35to40 = new TH2F("hz8_35to40","rec, gen del_R_wta_vs_g_35to40",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_40to45 = new TH1F("h8_40to45","rec, gen del_R_wta_vs_g_40to45",100,-0.03,0.45);
    h8_40to45->SetLineColor(kBlue);
    //h8_40to45->GetYaxis()->SetTitle("Probability of R"); h8_40to45->GetXaxis()->SetTitle("R");
    h8b_40to45 = new TH1F("h8b_40to45","rec, gen del_R_wta_vs_g_40to45",100,-0.03,0.45);
    h8b_40to45->SetLineColor(kRed);
    //h8b_40to45->GetYaxis()->SetTitle("Probability of R"); h8b_40to45->GetXaxis()->SetTitle("R");
    h8z_40to45 = new TH2F("h8z_40to45","rec, gen del_R_wta_vs_g_40to45",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_45to50 = new TH1F("h8_45to50","rec, gen del_R_wta_vs_g_45to50",100,-0.03,0.45);
    h8_45to50->SetLineColor(kBlue);
    //h8_45to50->GetYaxis()->SetTitle("Probability of R");h8_45to50->GetXaxis()->SetTitle("R");
    h8b_45to50 = new TH1F("h8b_45to50","rec, gen del_R_wta_vs_g_45to50",100,-0.03,0.45);
    h8b_45to50->SetLineColor(kRed);
    //h8b_45to50->GetYaxis()->SetTitle("Probability of R"); h8b_45to50->GetXaxis()->SetTitle("R");
    h8z_45to50 = new TH2F("h8z_45to50","rec, gen del_R_wta_vs_g_45to50",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_50to55 = new TH1F("h8_50to55","rec, gen del_R_wta_vs_g_50to55",100,-0.03,0.45);
    h8_50to55->SetLineColor(kBlue); 
    //h8_50to55->GetYaxis()->SetTitle("Probability of R");  h8_50to55->GetXaxis()->SetTitle("R");
    h8b_50to55 = new TH1F("h8b_50to55","rec, gen del_R_wta_vs_g_50to55",100,-0.03,0.45);
    h8b_50to55->SetLineColor(kRed);
    //h8b_50to55->GetYaxis()->SetTitle("Probability of R"); h8b_50to55->GetXaxis()->SetTitle("R");
    h8z_50to55 = new TH2F("h8z_50to55","rec, gen del_R_wta_vs_g_50to55",100,-0.03,0.45,100,-0.03,0.45);
    
    h8_55to60 = new TH1F("h8_55to60","rec, gen del_R_wta_vs_g_55to60",100,-0.03,0.45);
    h8_55to60->SetLineColor(kBlue);
    //h8_55to60->GetYaxis()->SetTitle("Probability of R"); h8_55to60->GetXaxis()->SetTitle("R");
    h8b_55to60 = new TH1F("h8b_55to60","rec, gen del_R_wta_vs_g_55to60",100,-0.03,0.45);
    h8b_55to60->SetLineColor(kRed);
    //h8b_55to60->GetYaxis()->SetTitle("Probability of R"); h8b_55to60->GetXaxis()->SetTitle("R");
    h8z_55to60 = new TH2F("h8z_55to60","rec, gen del_R_wta_vs_g_55to60",100,-0.03,0.45,100,-0.03,0.45);
    
    
      h9 = new TH2F("h9", "rec del phi vs del eta of E,g",100,-0.2,0.2,100,-0.2,0.2);
      h9->GetXaxis()->SetTitle("del eta");h9->GetXaxis()->CenterTitle();
    h9->GetYaxis()->SetTitle("del phi");h9->GetYaxis()->CenterTitle();

    h9b = new TH2F("h9b", "gen del phi vs del eta of E,g",100,-0.2,0.2,100,-0.2,0.2);
      h9b->GetXaxis()->SetTitle("del eta");h9b->GetXaxis()->CenterTitle();
    h9b->GetYaxis()->SetTitle("del phi");h9b->GetYaxis()->CenterTitle();

       h10 = new TH2F("h10", "rec del phi vs del eta of E,wta",100,-0.2,0.2,100,-0.2,0.2);
       h10->GetXaxis()->SetTitle("del eta");h10->GetXaxis()->CenterTitle();
    h10->GetYaxis()->SetTitle("del phi");h10->GetYaxis()->CenterTitle();

     h10b = new TH2F("h10b", "gen del phi vs del eta of E,wta",100,-0.2,0.2,100,-0.2,0.2);
       h10b->GetXaxis()->SetTitle("del eta");h10b->GetXaxis()->CenterTitle();
    h10b->GetYaxis()->SetTitle("del phi");h10b->GetYaxis()->CenterTitle();
    
        h11 = new TH2F("h11", "rec del phi vs del eta of wta,g",100,-0.2,0.2,100,-0.2,0.2);
	 h11->GetXaxis()->SetTitle("del eta");h11->GetXaxis()->CenterTitle();
    h11->GetYaxis()->SetTitle("del phi");h11->GetYaxis()->CenterTitle();

    h11b = new TH2F("h11b", "gen del phi vs del eta of wta,g",100,-0.2,0.2,100,-0.2,0.2);
         h11b->GetXaxis()->SetTitle("del eta");h11b->GetXaxis()->CenterTitle();
    h11b->GetYaxis()->SetTitle("del phi");h11b->GetYaxis()->CenterTitle();
    
    h12_5to10 = new TH1F("h12_5to10","rec gen del eta E g 5 to 10",100,-0.2,0.2);
    h12_5to10->SetLineColor(kBlue);
    h12b_5to10 = new TH1F("h12b_5to10","rec gen del eta E g 5 to 10",100,-0.2,0.2);
    h12b_5to10->SetLineColor(kRed);
    h12z_5to10 = new TH2F("h12z_5to10","rec gen del eta E g 5 to 10",100,-0.4,0.4,100,-0.4,0.4);
    
    h12_10to15 = new TH1F("h12_10to15","rec gen del eta E g 10to15",100,-0.2,0.2);
    h12_10to15->SetLineColor(kBlue);
    h12b_10to15 = new TH1F("h12b_10to15","rec gen del eta E g 10to15",100,-0.2,0.2);
    h12b_10to15->SetLineColor(kRed);
    h12z_10to15 = new TH2F("h12z_10to15","rec gen del eta E g 10to15",100,-0.4,0.4,100,-0.4,0.4);
    
    h12_15to20 = new TH1F("h12_15to20","rec gen del eta E g 15to20",100,-0.2,0.2);
    h12_15to20->SetLineColor(kBlue);
    h12b_15to20 = new TH1F("h12b_15to20","rec gen del eta E g 15to20",100,-0.2,0.2);
    h12b_15to20->SetLineColor(kRed);
    h12z_15to20 = new TH2F("h12z_15to20","rec gen del eta E g 15to20",100,-0.4,0.4,100,-0.4,0.4);
    
    h12_20to25 = new TH1F("h12_20to25","rec gen del eta E g 20to25",100,-0.2,0.2);
    h12_20to25->SetLineColor(kBlue);
    h12b_20to25 = new TH1F("h12b_20to25","rec gen del eta E g 20to25",100,-0.2,0.2);
    h12b_20to25->SetLineColor(kRed);
    h12z_20to25 = new TH2F("h12z_20to25","rec gen del eta E g 20to25",100,-0.4,00.4,100,-0.4,0.4);
    
    h12_25to30 = new TH1F("h12_25to30","rec gen del eta E g 25to30",100,-0.2,0.2);
    h12_25to30->SetLineColor(kBlue);
    h12b_25to30 = new TH1F("h12b_25to30","rec gen del eta E g 25to30",100,-0.2,0.2);
    h12b_25to30->SetLineColor(kRed);
    h12z_25to30 = new TH2F("h12z_25to30","rec gen del eta E g 25to30",100,-0.4,0.4,100,-0.4,0.4);
    
    h12_30to35 = new TH1F("h12_30to35","rec gen del eta E g 30to35",100,-0.2,0.2);
    h12_30to35->SetLineColor(kBlue);
    h12b_30to35 = new TH1F("h12b_30to35","rec gen del eta E g 30to35",100,-0.2,0.2);
    h12b_30to35->SetLineColor(kRed);
    h12z_30to35 = new TH2F("h12z_30to35","rec gen del eta E g 30to35",100,-0.4,0.4,100,-0.4,0.4);
    
    h12_35to40 = new TH1F("h12_35to40","rec gen del eta E g 35to40",100,-0.2,0.2);
    h12_35to40->SetLineColor(kBlue);
    h12b_35to40 = new TH1F("h12b_35to40","rec gen del eta E g 35to40",100,-0.2,0.2);
    h12b_35to40->SetLineColor(kRed);
    h12z_35to40 = new TH2F("h12z_35to40","rec gen del eta E g 35to40",100,-0.4,0.4,100,-0.4,0.4);
    
    h12_40to45 = new TH1F("h12_40to45","rec gen del eta E g 40to45",100,-0.2,0.2);
    h12_40to45->SetLineColor(kBlue);
    h12b_40to45 = new TH1F("h12b_40to45","rec gen del eta E g 40to45",100,-0.2,0.2);
    h12b_40to45->SetLineColor(kRed);
    h12z_40to45 = new TH2F("h12z_40to45","rec gen del eta E g 40to45",100,-0.2,0.2,100,-0.2,0.2);
    
    h12_45to50 = new TH1F("h12_45to50","rec gen del eta E g 45to50",100,-0.2,0.2);
    h12_45to50->SetLineColor(kBlue);
    h12b_45to50 = new TH1F("h12b_45to50","rec gen del eta E g 45to50",100,-0.2,0.2);
    h12b_45to50->SetLineColor(kRed);
    h12z_45to50 = new TH2F("h12z_45to50","rec gen del eta E g 45to50",100,-0.2,0.2,100,-0.2,0.2);
    
    h12_50to55 = new TH1F("h12_50to55","rec gen del eta E g 50to550",100,-0.2,0.2);
    h12_50to55->SetLineColor(kBlue);
    h12b_50to55 = new TH1F("h12b_50to55","rec gen del eta E g 50to55",100,-0.2,0.2);
    h12b_50to55->SetLineColor(kRed);
    h12z_50to55 = new TH2F("h12z_50to55","rec gen del eta E g 50to550",100,-0.2,0.2,100,-0.2,0.2);
    
    h12_55to60 = new TH1F("h12_55to60","rec gen del eta E g 55to60",100,-0.2,0.2);
    h12_55to60->SetLineColor(kBlue);
    h12b_55to60 = new TH1F("h12b_55to60","rec gen del eta E g 55to60",100,-0.2,0.2);
    h12b_55to60->SetLineColor(kRed);
    h12z_55to60 = new TH2F("h12z_55to60","rec gen del eta E g 55to60",100,-0.2,0.2,100,-0.2,0.2);
    
    h13_5to10 = new TH1F("h13_5to10","rec gen del phi E g_5to10",100,0,0.2);
    h13_5to10->SetLineColor(kBlue);
    h13b_5to10 = new TH1F("h13b_5to10","rec gen del phi E g_5to10",100,0,0.2);
    h13b_5to10->SetLineColor(kRed);
    h13z_5to10 = new TH2F("h13z_5to10","rec gen del phi E g_5to10",100,0,0.2,100,0,0.2);
    
    h13_10to15 = new TH1F("h13_10to15","rec gen del phi E g_10to15",100,0,0.2);
    h13_10to15->SetLineColor(kBlue);
    h13b_10to15 = new TH1F("h13b_10to15","rec gen del phi E g_10to15",100,0,0.2);
    h13b_10to15->SetLineColor(kRed);
    h13z_10to15 = new TH2F("h13z_10to15","rec gen del phi E g_10to15",100,0,0.2,100,0,0.2);
    
    h13_15to20 = new TH1F("h13_15to20","rec gen del phi E g_15to20",100,0,0.2);
    h13_15to20->SetLineColor(kBlue);
    h13b_15to20 = new TH1F("h13b_15to20","rec gen del phi E g_15to20",100,0,0.2);
    h13b_15to20->SetLineColor(kRed);
    h13z_15to20 = new TH2F("h13_z15to20","rec gen del phi E g_15to20",100,0,0.2,100,0,0.2);
    
    h13_20to25 = new TH1F("h13_20to25","rec gen del phi E g_20to25",100,0,0.2);
    h13_20to25->SetLineColor(kBlue);
    h13b_20to25 = new TH1F("h13b_20to25","rec gen del phi E g_20to25",100,0,0.2);
    h13b_20to25->SetLineColor(kRed);
    h13z_20to25 = new TH2F("h13z_20to25","rec gen del phi E g_20to25",100,0,0.2,100,0,0.2);
    
    h13_25to30 = new TH1F("h13_25to30","rec gen del phi E g_25to30",100,0,0.2);
    h13_25to30->SetLineColor(kBlue);
    h13b_25to30 = new TH1F("h13b_25to30","rec gen del phi E g_25to30",100,0,0.2);
    h13b_25to30->SetLineColor(kRed);
    h13z_25to30 = new TH2F("h13z_25to30","rec gen del phi E g_25to30",100,0,0.2,100,0,0.2);
    
    h13_30to35 = new TH1F("h13_30to35","rec gen del phi E g_30to35",100,0,0.2);
    h13_30to35->SetLineColor(kBlue);
    h13b_30to35 = new TH1F("h13b_30to35","rec gen del phi E g_30to35",100,0,0.2);
    h13b_30to35->SetLineColor(kRed);
    h13z_30to35 = new TH2F("h13z_30to35","rec gen del phi E g_30to35",100,0,0.2,100,0,0.2);
    
    h13_35to40 = new TH1F("h13_35to40","rec gen del phi E g_35to40",100,0,0.2);
    h13_35to40->SetLineColor(kBlue);
    h13b_35to40 = new TH1F("h13b_35to40","rec gen del phi E g_35to40",100,0,0.2);
    h13b_35to40->SetLineColor(kRed);
    h13z_35to40 = new TH2F("h1z3_35to40","rec gen del phi E g_35to40",100,0,0.2,100,0,0.2);
    
    h13_40to45 = new TH1F("h13_40to45","rec gen del phi E g_40to45",100,0,0.2);
    h13_40to45->SetLineColor(kBlue);
    h13b_40to45 = new TH1F("h13b_40to45","rec gen del phi E g_40to45",100,0,0.2);
    h13b_40to45->SetLineColor(kRed);
    h13z_40to45 = new TH2F("h13z_40to45","rec gen del phi E g_40to45",100,0,0.2,100,0,0.2);
    
    h13_45to50 = new TH1F("h13_45to50","rec gen del phi E g_45to50",100,0,0.2);
    h13_45to50->SetLineColor(kBlue);
    h13b_45to50 = new TH1F("h13b_45to50","rec gen del phi E g_45to50",100,0,0.2);
    h13b_45to50->SetLineColor(kRed);
    h13z_45to50 = new TH2F("h13z_45to50","rec gen del phi E g_45to50",100,0,0.2,100,0,0.2);
    
    h13_50to55 = new TH1F("h13_50to55","rec gen del phi E g_50to55",100,0,0.2);
    h13_50to55->SetLineColor(kBlue);
    h13b_50to55 = new TH1F("h13b_50to55","rec gen del phi E g_50to55",100,0,0.2);
    h13b_50to55->SetLineColor(kRed);
    h13z_50to55 = new TH2F("h1z3_50to55","rec gen del phi E g_50to55",100,0,0.2,100,0,0.2);
    
    h13_55to60 = new TH1F("h13_55to60","rec gen del phi E g_55to60",100,0,0.2);
    h13_55to60->SetLineColor(kBlue);
    h13b_55to60 = new TH1F("h13b_55to60","rec gen del phi E g_55to60",100,0,0.2);
    h13b_55to60->SetLineColor(kRed);
    h13z_55to60 = new TH2F("h13z_55to60","rec gen del phi E g_55to60",100,0,0.2,100,0,0.2);
    
    h14_5to10 = new TH1F("h14_5to10","rec gen del eta E wta_5to10",100,-0.4,0.4);
    h14_5to10->SetLineColor(kBlue);
    h14b_5to10 = new TH1F("h14b_5to10","rec gen del eta E wta_5to10",100,-0.4,0.4);
    h14b_5to10->SetLineColor(kRed);
    h14z_5to10 = new TH2F("h1z4_5to10","rec gen del eta E wta_5to10",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_10to15 = new TH1F("h14_10to15","rec gen del eta E wta_10to15",100,-0.4,0.4);
    h14_10to15->SetLineColor(kBlue);
    h14b_10to15 = new TH1F("h14b_10to15","rec gen del eta E wta_10to15",100,-0.4,0.4);
    h14b_10to15->SetLineColor(kRed);
    h14z_10to15 = new TH2F("h14z_10to15","rec gen del eta E wta_10to15",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_15to20 = new TH1F("h14_15to20","rec gen del eta E wta_15to20",100,-0.4,0.4);
    h14_15to20->SetLineColor(kBlue);
    h14b_15to20 = new TH1F("h14b_15to20","rec gen del eta E wta_15to20",100,-0.4,0.4);
    h14b_15to20->SetLineColor(kRed);
    h14z_15to20 = new TH2F("h14z_15to20","rec gen del eta E wta_15to20",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_20to25 = new TH1F("h14_20to25","rec gen del eta E wta_20to25",100,-0.4,0.4);
    h14_20to25->SetLineColor(kBlue);
    h14b_20to25 = new TH1F("h14b_20to25","rec gen del eta E wta_20to25",100,-0.4,0.4);
    h14b_20to25->SetLineColor(kRed);
    h14z_20to25 = new TH2F("h14z_20to25","rec gen del eta E wta_20to25",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_25to30 = new TH1F("h14_25to30","rec gen del eta E wta_25to30",100,-0.4,0.4);
    h14_25to30->SetLineColor(kBlue);
    h14b_25to30 = new TH1F("h14b_25to30","rec gen del eta E wta_25to30",100,-0.4,0.4);
    h14b_25to30->SetLineColor(kRed);
    h14z_25to30 = new TH2F("h14z_25to30","rec gen del eta E wta_25to30",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_30to35 = new TH1F("h14_30to35","rec gen del eta E wta_30to35",100,-0.4,0.4);
    h14_30to35->SetLineColor(kBlue);
    h14b_30to35 = new TH1F("h14b_30to35","rec gen del eta E wta_30to35",100,-0.4,0.4);
    h14b_30to35->SetLineColor(kRed);
    h14z_30to35 = new TH2F("h14z_30to35","rec gen del eta E wta_30to35",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_35to40 = new TH1F("h14_35to40","rec gen del eta E wta_35to40",100,-0.4,0.4);
    h14_35to40->SetLineColor(kBlue);
    h14b_35to40 = new TH1F("h14b_35to40","rec gen del eta E wta_35to40",100,-0.4,0.4);
    h14b_35to40->SetLineColor(kRed);
    h14z_35to40 = new TH2F("h14z_35to40","rec gen del eta E wta_35to40",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_40to45 = new TH1F("h14_40to45","rec gen del eta E wta_40to45",100,-0.4,0.4);
    h14_40to45->SetLineColor(kBlue);
    h14b_40to45 = new TH1F("h14b_40to45","rec gen del eta E wta_40to45",100,-0.4,0.4);
    h14b_40to45->SetLineColor(kRed);
    h14z_40to45 = new TH2F("hz14_40to45","rec gen del eta E wta_40to45",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_45to50 = new TH1F("h14_45to50","rec gen del eta E wta_45to50",100,-0.4,0.4);
    h14_45to50->SetLineColor(kBlue);
    h14b_45to50 = new TH1F("h14b_45to50","rec gen del eta E wta_45to50",100,-0.4,0.4);
    h14b_45to50->SetLineColor(kRed);
    h14z_45to50 = new TH2F("h14z_45to50","rec gen del eta E wta_45to50",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_50to55 = new TH1F("h14_50to55","rec gen del eta E wta_50to55",100,-0.4,0.4);
    h14_50to55->SetLineColor(kBlue);
    h14b_50to55 = new TH1F("h14b_50to55","rec gen del eta E wta_50to55",100,-0.4,0.4);
    h14b_50to55->SetLineColor(kRed);
    h14z_50to55 = new TH2F("h14z_50to55","rec gen del eta E wta_50to55",100,-0.4,0.4,100,-0.4,0.4);
    
    h14_55to60 = new TH1F("h14_55to60","rec gen del eta E wta_55to60",100,-0.4,0.4);
    h14_55to60->SetLineColor(kBlue);
    h14b_55to60 = new TH1F("h14b_55to60","rec gen del eta E wta_55to60",100,-0.4,0.4);
    h14b_55to60->SetLineColor(kRed);
    h14z_55to60 = new TH2F("h14z_55to60","rec gen del eta E wta_55to60",100,-0.4,0.4,100,-0.4,0.4);
   
    h15_5to10 = new TH1F("h15_5to10","rec gen del phi E wta_5to10",100,0,0.4);
    h15_5to10->SetLineColor(kBlue);
    h15b_5to10 = new TH1F("h15b_5to10","rec gen del phi E wta_5to10",100,0,0.4);
    h15b_5to10->SetLineColor(kRed);
    h15z_5to10 = new TH2F("h15z_5to10","rec gen del phi E wta_5to10",100,0,0.4,100,0,0.4);
    
    h15_10to15 = new TH1F("h15_10to15","rec gen del phi E wta_10to15",100,0,0.4);
    h15_10to15->SetLineColor(kBlue);
    h15b_10to15 = new TH1F("h15b_10to15","rec gen del phi E wta_10to15",100,0,0.4);
    h15b_10to15->SetLineColor(kRed);
    h15z_10to15 = new TH2F("h15z_10to15","rec gen del phi E wta_10to15",100,0,0.4,100,0,0.4);
    
    h15_15to20 = new TH1F("h15_15to20","rec gen del phi E wta_15to20",100,0,0.4);
    h15_15to20->SetLineColor(kBlue);
    h15b_15to20 = new TH1F("h15b_15to20","rec gen del phi E wta_15to20",100,0,0.4);
    h15b_15to20->SetLineColor(kRed);
    h15z_15to20 = new TH2F("h15z_15to20","rec gen del phi E wta_15to20",100,0,0.4,100,0,0.4);
    
    h15_20to25 = new TH1F("h15_20to25 ","rec gen del phi E wta_20to25 ",100,0,0.4);
    h15_20to25 ->SetLineColor(kBlue);
    h15b_20to25  = new TH1F("h15b_20to25 ","rec gen del phi E wta_20to25 ",100,0,0.4);
    h15b_20to25 ->SetLineColor(kRed);
    h15z_20to25 = new TH2F("h15z_20to25 ","rec gen del phi E wta_20to25 ",100,0,0.4,100,0,0.4);
    
    h15_25to30 = new TH1F("h15_25to30","rec gen del phi E wta_25to30",100,0,0.4);
    h15_25to30->SetLineColor(kBlue);
    h15b_25to30 = new TH1F("h15b_25to30","rec gen del phi E wta_25to30",100,0,0.4);
    h15b_25to30->SetLineColor(kRed);
    h15z_25to30 = new TH2F("h15z_25to30","rec gen del phi E wta_25to30",100,0,0.4,100,0,0.4);
    
    h15_30to35 = new TH1F("h15_30to35","rec gen del phi E wta_30to35",100,0,0.4);
    h15_30to35->SetLineColor(kBlue);
    h15b_30to35 = new TH1F("h15b_30to35","rec gen del phi E wta_30to35",100,0,0.4);
    h15b_30to35->SetLineColor(kRed);
    h15z_30to35 = new TH2F("h15z_30to35","rec gen del phi E wta_30to35",100,0,0.4,100,0,0.4);
    
    h15_35to40 = new TH1F("h15_35to40","rec gen del phi E wta_35to40",100,0,0.4);
    h15_35to40->SetLineColor(kBlue);
    h15b_35to40 = new TH1F("h15b_35to40","rec gen del phi E wta_35to40",100,0,0.4);
    h15b_35to40->SetLineColor(kRed);
    h15z_35to40 = new TH2F("h15z_35to40","rec gen del phi E wta_35to40",100,0,0.4,100,0,0.4);
    
    h15_40to45 = new TH1F("h15_40to45","rec gen del phi E wta_40to45",100,0,0.4);
    h15_40to45->SetLineColor(kBlue);
    h15b_40to45 = new TH1F("h15b_40to45","rec gen del phi E wta_40to45",100,0,0.4);
    h15b_40to45->SetLineColor(kRed);
    h15z_40to45 = new TH2F("h15z_40to45","rec gen del phi E wta_40to45",100,0,0.4,100,0,0.4);
    
    h15_45to50 = new TH1F("h15_45to50","rec gen del phi E wta_45to50",100,0,0.4);
    h15_45to50->SetLineColor(kBlue);
    h15b_45to50 = new TH1F("h15b_45to50","rec gen del phi E wta_45to50",100,0,0.4);
    h15b_45to50->SetLineColor(kRed);
    h15z_45to50 = new TH2F("h15z_45to50","rec gen del phi E wta_45to50",100,0,0.4,100,0,0.4);
    
    h15_50to55 = new TH1F("h15_50to55","rec gen del phi E wta_50to55",100,0,0.4);
    h15_50to55->SetLineColor(kBlue);
    h15b_50to55 = new TH1F("h15b_50to55","rec gen del phi E wta_50to55",100,0,0.4);
    h15b_50to55->SetLineColor(kRed);
    h15z_50to55 = new TH2F("h15z_50to55","rec gen del phi E wta_50to55",100,0,0.4,100,0,0.4);
    
    h15_55to60 = new TH1F("h15_55to60","rec gen del phi E wta_55to60",100,0,0.4);
    h15_55to60->SetLineColor(kBlue);
    h15b_55to60 = new TH1F("h15b_55to60","rec gen del phi E wta_55to60",100,0,0.4);
    h15b_55to60->SetLineColor(kRed);
    h15z_55to60 = new TH2F("h15z_55to60","rec gen del phi E wta_55to60",100,0,0.4,100,0,0.4);
    
    h16_5to10 = new TH1F("h16_5to10","rec gen del eta g wta_5to10",100,-0.4,0.4);
    h16_5to10->SetLineColor(kBlue);
    h16b_5to10 = new TH1F("h16b_5to10","rec gen del eta g wta_5to10",100,-0.4,0.4);
    h16b_5to10->SetLineColor(kRed);
    h16z_5to10 = new TH2F("h16z_5to10","rec gen del eta g wta_5to10",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_10to15 = new TH1F("h16_10to15","rec gen del eta g wta_10to15",100,-0.4,0.4);
    h16_10to15->SetLineColor(kBlue);
    h16b_10to15 = new TH1F("h16b_10to15","rec gen del eta g wta_10to15",100,-0.4,0.4);
    h16b_10to15->SetLineColor(kRed);
    h16z_10to15 = new TH2F("h16z_10to15","rec gen del eta g wta_10to15",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_15to20 = new TH1F("h16_15to20","rec gen del eta g wta_15to20",100,-0.4,0.4);
    h16_15to20->SetLineColor(kBlue);
    h16b_15to20 = new TH1F("h16b_15to20","rec gen del eta g wta_15to20",100,-0.4,0.4);
    h16b_15to20->SetLineColor(kRed);
    h16z_15to20 = new TH2F("h16z_15to20","rec gen del eta g wta_15to20",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_20to25 = new TH1F("h16_20to25","rec gen del eta g wta_20to25",100,-0.4,0.4);
    h16_20to25->SetLineColor(kBlue);
    h16b_20to25 = new TH1F("h16b_20to25","rec gen del eta g wta_20to25",100,-0.4,0.4);
    h16b_20to25->SetLineColor(kRed);
    h16z_20to25 = new TH2F("h16z_20to25","rec gen del eta g wta_20to25",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_25to30 = new TH1F("h16_25to30","rec gen del eta g wta_25to30",100,-0.4,0.4);
    h16_25to30->SetLineColor(kBlue);
    h16b_25to30 = new TH1F("h16b_25to30","rec gen del eta g wta_25to30",100,-0.4,0.4);
    h16b_25to30->SetLineColor(kRed);
    h16z_25to30 = new TH2F("h16z_25to30","rec gen del eta g wta_25to30",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_30to35 = new TH1F("h16_30to35","rec gen del eta g wta_30to35",100,-0.4,0.4);
    h16_30to35->SetLineColor(kBlue);
    h16b_30to35 = new TH1F("h16b_30to35","rec gen del eta g wta_30to35",100,-0.4,0.4);
    h16b_30to35->SetLineColor(kRed);
    h16z_30to35 = new TH2F("h16z_30to35","rec gen del eta g wta_30to35",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_35to40 = new TH1F("h16_35to40","rec gen del eta g wta_35to40",100,-0.4,0.4);
    h16_35to40->SetLineColor(kBlue);
    h16b_35to40 = new TH1F("h16b_35to40","rec gen del eta g wta_35to40",100,-0.4,0.4);
    h16b_35to40->SetLineColor(kRed);
    h16z_35to40 = new TH2F("h16z_35to40","rec gen del eta g wta_35to40",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_40to45 = new TH1F("h16_40to45","rec gen del eta g wta_40to45",100,-0.4,0.4);
    h16_40to45->SetLineColor(kBlue);
    h16b_40to45 = new TH1F("h16b_40to45","rec gen del eta g wta_40to45",100,-0.4,0.4);
    h16b_40to45->SetLineColor(kRed);
    h16z_40to45 = new TH2F("h16z_40to45","rec gen del eta g wta_40to45",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_45to50 = new TH1F("h16_45to50","rec gen del eta g wta_45to50",100,-0.4,0.4);
    h16_45to50->SetLineColor(kBlue);
    h16b_45to50 = new TH1F("h16b_45to50","rec gen del eta g wta_45to50",100,-0.4,0.4);
    h16b_45to50->SetLineColor(kRed);
    h16z_45to50 = new TH2F("h16z_45to50","rec gen del eta g wta_45to50",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_50to55 = new TH1F("h16_50to55","rec gen del eta g wta_50to55",100,-0.4,0.4);
    h16_50to55->SetLineColor(kBlue);
    h16b_50to55 = new TH1F("h16b_50to55","rec gen del eta g wta_50to55",100,-0.4,0.4);
    h16b_50to55->SetLineColor(kRed);
    h16z_50to55 = new TH2F("h16z_50to55","rec gen del eta g wta_50to55",100,-0.4,0.4,100,-0.4,0.4);
    
    h16_55to60 = new TH1F("h16_55to60","rec gen del eta g wta_55to60",100,-0.4,0.4);
    h16_55to60->SetLineColor(kBlue);
    h16b_55to60 = new TH1F("h16b_55to60","rec gen del eta g wta_55to60",100,-0.4,0.4);
    h16b_55to60->SetLineColor(kRed);
    h16z_55to60 = new TH2F("h16z_55to60","rec gen del eta g wta_55to60",100,-0.4,0.4,100,-0.4,0.4);
    
    h17_5to10 = new TH1F("h17_5to10","rec gen del phi g wta_5to10",100,0,0.4);
    h17_5to10->SetLineColor(kBlue);
    h17b_5to10 = new TH1F("h17b_5to10","rec gen del phi g wta_5to10",100,0,0.4);
    h17b_5to10->SetLineColor(kRed);
    h17z_5to10 = new TH2F("h17z_5to10","rec gen del phi g wta_5to10",100,0,0.4,100,0,0.4);
    
    h17_10to15 = new TH1F("h17_10to15","rec gen del phi g wta_10to15",100,0,0.4);
    h17_10to15->SetLineColor(kBlue);
    h17b_10to15 = new TH1F("h17b_10to15","rec gen del phi g wta_10to15",100,0,0.4);
    h17b_10to15->SetLineColor(kRed);
    h17z_10to15 = new TH2F("h17z_10to15","rec gen del phi g wta_10to15",100,0,0.4,100,0,0.4);
    
    h17_15to20 = new TH1F("h17_15to20","rec gen del phi g wta_15to20",100,0,0.4);
    h17_15to20->SetLineColor(kBlue);
    h17b_15to20 = new TH1F("h17b_15to20","rec gen del phi g wta_15to20",100,0,0.4);
    h17b_15to20->SetLineColor(kRed);
    h17z_15to20 = new TH2F("h17z_15to20","rec gen del phi g wta_15to20",100,0,0.4,100,0,0.4);
    
    h17_20to25 = new TH1F("h17_20to25","rec gen del phi g wta_20to25",100,0,0.4);
    h17_20to25->SetLineColor(kBlue);
    h17b_20to25 = new TH1F("h17b_20to25","rec gen del phi g wta_20to25",100,0,0.4);
    h17b_20to25->SetLineColor(kRed);
    h17z_20to25 = new TH2F("h17z_20to25","rec gen del phi g wta_20to25",100,0,0.4,100,0,0.4);
    
    h17_25to30 = new TH1F("h17_25to30","rec gen del phi g wta_25to30",100,0,0.4);
    h17_25to30->SetLineColor(kBlue);
    h17b_25to30 = new TH1F("h17b_25to30","rec gen del phi g wta_25to30",100,0,0.4);
    h17b_25to30->SetLineColor(kRed);
    h17z_25to30 = new TH2F("h17z_25to30","rec gen del phi g wta_25to30",100,0,0.4,100,0,0.4);
    
    h17_30to35 = new TH1F("h17_30to35","rec gen del phi g wta_30to35",100,0,0.4);
    h17_30to35->SetLineColor(kBlue);
    h17b_30to35 = new TH1F("h17b_30to35","rec gen del phi g wta_30to35",100,0,0.4);
    h17b_30to35->SetLineColor(kRed);
    h17z_30to35 = new TH2F("h17z_30to35","rec gen del phi g wta_30to35",100,0,0.4,100,0,0.4);
    
    h17_35to40 = new TH1F("h17_35to40","rec gen del phi g wta_35to40",100,0,0.4);
    h17_35to40->SetLineColor(kBlue);
    h17b_35to40 = new TH1F("h17b_35to40","rec gen del phi g wta_35to40",100,0,0.4);
    h17b_35to40->SetLineColor(kRed);
    h17z_35to40 = new TH2F("h17z_35to40","rec gen del phi g wta_35to40",100,0,0.4,100,0,0.4);
    
    h17_40to45 = new TH1F("h17_40to45","rec gen del phi g wta_40to45",100,0,0.4);
    h17_40to45->SetLineColor(kBlue);
    h17b_40to45 = new TH1F("h17b_40to45","rec gen del phi g wta_40to45",100,0,0.4);
    h17b_40to45->SetLineColor(kRed);
    h17z_40to45 = new TH2F("h17z_40to45","rec gen del phi g wta_40to45",100,0,0.4,100,0,0.4);
    
    h17_45to50 = new TH1F("h17_45to50","rec gen del phi g wta_45to50",100,0,0.4);
    h17_45to50->SetLineColor(kBlue);
    h17b_45to50 = new TH1F("h17b_45to50","rec gen del phi g wta_45to50",100,0,0.4);
    h17b_45to50->SetLineColor(kRed);
    h17z_45to50 = new TH2F("h17z_45to50","rec gen del phi g wta_45to50",100,0,0.4,100,0,0.4);
    
    h17_50to55 = new TH1F("h17_50to55","rec gen del phi g wta_50to55",100,0,0.4);
    h17_50to55->SetLineColor(kBlue);
    h17b_50to55 = new TH1F("h17b_50to55","rec gen del phi g wta_50to55",100,0,0.4);
    h17b_50to55->SetLineColor(kRed);
    h17z_50to55 = new TH2F("h17z_50to55","rec gen del phi g wta_50to55",100,0,0.4,100,0,0.4);
    
    h17_55to60 = new TH1F("h17_55to60","rec gen del phi g wta_55to60",100,0,0.4);
    h17_55to60->SetLineColor(kBlue);
    h17b_55to60 = new TH1F("h17b_55to60","rec gen del phi g wta_55to60",100,0,0.4);
    h17b_55to60->SetLineColor(kRed);
    h17z_55to60 = new TH2F("h17z_55to60","rec gen del phi g wta_55to60",100,0,0.4,100,0,0.4);
    
    
    del_pt_E = new TH1F(" del_pt_E","del p rec vs gen E g wta scheme",100,-45,70);
    del_pt_E->SetLineColor(kBlue);
    del_phi_E = new TH1F("del_phi_E","del phi rec vs gen E g wta scheme",100,-0.42,0.42);
    del_phi_E->SetLineColor(kBlue);
    del_eta_E = new TH1F("del_eta_E","del eta rec vs gen E g wta scheme",100,-0.42,0.42);
    del_eta_E->SetLineColor(kBlue);
    
    del_pt_g = new TH1F(" del_pt_g","del p rec vs gen E g wta scheme",100,-45,70);
    del_pt_g->SetLineColor(kRed);
    del_phi_g =	new TH1F("del_phi_g","del phi rec vs gen E g wta scheme",100,-0.42,0.42);
    del_phi_g->SetLineColor(kRed);
    del_eta_g =	new TH1F("del_eta_g","del eta rec vs gen E g wta scheme",100,-0.42,0.42);
    del_eta_g->SetLineColor(kRed);
    
    del_pt_w = new TH1F(" del_pt_w","del p rec vs gen E g wta scheme",100,-45,70);
    del_pt_w->SetLineColor(kGreen);
    del_phi_w =	new TH1F("del_phi_w","del phi rec vs gen E g wta scheme",100,-0.42,0.42);
    del_phi_w->SetLineColor(kGreen);
    del_eta_w =	new TH1F("del_eta_w","del eta rec vs gen E g wta scheme",100,-0.42,0.42);
    del_eta_w->SetLineColor(kGreen);

    del_R_gen_rec_E_g_5to10 = new TH1F("del_R_gen_rec_E_g_5to10","del_R_gen_rec_5to10",100,-0.4,0.4);
    del_R_gen_rec_E_g_5to10->SetLineColor(kBlue);
    del_R_gen_rec_E_W_5to10= new TH1F("del_R_gen_rec_E_W_5to10","del_R_gen_rec_5to10",100,-0.4,0.4);
    del_R_gen_rec_E_W_5to10->SetLineColor(kGreen);
    del_R_gen_rec_W_g_5to10 = new TH1F("del_R_gen_rec_W_g_5to10","del_R_gen_rec_5to10",100,-0.4,0.4);
    del_R_gen_rec_W_g_5to10->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_10to15 = new TH1F("del_R_gen_rec_E_g_10to15","del_R_gen_rec_10to15",100,-0.4,0.4);
    del_R_gen_rec_E_g_10to15->SetLineColor(kBlue);
    del_R_gen_rec_E_W_10to15 = new TH1F("del_R_gen_rec_E_W_10to15","del_R_gen_rec_10to15",100,-0.4,0.4);
    del_R_gen_rec_E_W_10to15->SetLineColor(kGreen);
    del_R_gen_rec_W_g_10to15 = new TH1F("del_R_gen_rec_W_g_10to15","del_R_gen_rec_10to15",100,-0.4,0.4);
    del_R_gen_rec_W_g_10to15->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_15to20 = new TH1F("del_R_gen_rec_E_g_15to20","del_R_gen_rec_15to20",100,-0.4,0.4);
    del_R_gen_rec_E_g_15to20->SetLineColor(kBlue);
    del_R_gen_rec_E_W_15to20 = new TH1F("del_R_gen_rec_E_W_15to20","del_R_gen_rec_15to20",100,-0.4,0.4);
    del_R_gen_rec_E_W_15to20->SetLineColor(kGreen);
    del_R_gen_rec_W_g_15to20 = new TH1F("del_R_gen_rec_W_g_15to20","del_R_gen_rec_15to20",100,-0.4,0.4);
    del_R_gen_rec_W_g_15to20->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_20to25 = new TH1F("del_R_gen_rec_E_g_20to25","del_R_gen_rec_20to25",100,-0.4,0.4);
    del_R_gen_rec_E_g_20to25->SetLineColor(kBlue);
    del_R_gen_rec_E_W_20to25 = new TH1F("del_R_gen_rec_E_W_20to25","del_R_gen_rec_20to25",100,-0.4,0.4);
    del_R_gen_rec_E_W_20to25->SetLineColor(kGreen);
    del_R_gen_rec_W_g_20to25 = new TH1F("del_R_gen_rec_W_g_20to25","del_R_gen_rec_20to25",100,-0.4,0.4);
    del_R_gen_rec_W_g_20to25->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_25to30 = new TH1F("del_R_gen_rec_E_g_25to30","del_R_gen_rec_25to30",100,-0.4,0.4);
    del_R_gen_rec_E_g_25to30->SetLineColor(kBlue);
    del_R_gen_rec_E_W_25to30 = new TH1F("del_R_gen_rec_E_W_25to30","del_R_gen_rec_25to30",100,-0.4,0.4);
    del_R_gen_rec_E_W_25to30->SetLineColor(kGreen);
    del_R_gen_rec_W_g_25to30 = new TH1F("del_R_gen_rec_W_g_25to30","del_R_gen_rec_25to30",100,-0.4,0.4);
    del_R_gen_rec_W_g_25to30->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_30to35 = new TH1F("del_R_gen_rec_E_g_30to35","del_R_gen_rec_30to35",100,-0.4,0.4);
    del_R_gen_rec_E_g_30to35->SetLineColor(kBlue);
    del_R_gen_rec_E_W_30to35 = new TH1F("del_R_gen_rec_E_W_30to35","del_R_gen_rec_30to35",100,-0.4,0.4);
    del_R_gen_rec_E_W_30to35->SetLineColor(kGreen);
    del_R_gen_rec_W_g_30to35 = new TH1F("del_R_gen_rec_W_g_30to35","del_R_gen_rec_30to35",100,-0.4,0.4);
    del_R_gen_rec_W_g_30to35->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_35to40 = new TH1F("del_R_gen_rec_E_g_35to40","del_R_gen_rec_35to40",100,-0.4,0.4);
    del_R_gen_rec_E_g_35to40->SetLineColor(kBlue);
    del_R_gen_rec_E_W_35to40 = new TH1F("del_R_gen_rec_E_W_35to40","del_R_gen_rec_35to40",100,-0.4,0.4);
    del_R_gen_rec_E_W_35to40->SetLineColor(kGreen);
    del_R_gen_rec_W_g_35to40 = new TH1F("del_R_gen_rec_W_g_35to40","del_R_gen_rec_35to40",100,-0.4,0.4);
    del_R_gen_rec_W_g_35to40->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_40to45 = new TH1F("del_R_gen_rec_E_g_40to45","del_R_gen_rec_40to45",100,-0.4,0.4);
    del_R_gen_rec_E_g_40to45->SetLineColor(kBlue);
    del_R_gen_rec_E_W_40to45 = new TH1F("del_R_gen_rec_E_W_40to45","del_R_gen_rec_40to45",100,-0.4,0.4);
    del_R_gen_rec_E_W_40to45->SetLineColor(kGreen);
    del_R_gen_rec_W_g_40to45 = new TH1F("del_R_gen_rec_W_g_40to45","del_R_gen_rec_40to45",100,-0.4,0.4);
    del_R_gen_rec_W_g_40to45->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_45to50 = new TH1F("del_R_gen_rec_E_g_45to50","del_R_gen_rec_45to50",100,-0.4,0.4);
    del_R_gen_rec_E_g_45to50->SetLineColor(kBlue);
    del_R_gen_rec_E_W_45to50 = new TH1F("del_R_gen_rec_E_W_45to50","del_R_gen_rec_45to50",100,-0.4,0.4);
    del_R_gen_rec_E_W_45to50->SetLineColor(kGreen);
    del_R_gen_rec_W_g_45to50 = new TH1F("del_R_gen_rec_W_g_45to50","del_R_gen_rec_45to50",100,-0.4,0.4);
    del_R_gen_rec_W_g_45to50->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_50to55 = new TH1F("del_R_gen_rec_E_g_50to55","del_R_gen_rec_50to55",100,-0.4,0.4);
    del_R_gen_rec_E_g_50to55->SetLineColor(kBlue);
    del_R_gen_rec_E_W_50to55 = new TH1F("del_R_gen_rec_E_W_50to55","del_R_gen_rec_50to55",100,-0.4,0.4);
    del_R_gen_rec_E_W_50to55->SetLineColor(kGreen);
    del_R_gen_rec_W_g_50to55 = new TH1F("del_R_gen_rec_W_g_50to55","del_R_gen_rec_50to55",100,-0.4,0.4);
    del_R_gen_rec_W_g_50to55->SetLineColor(kRed);
    
    del_R_gen_rec_E_g_55to60 = new TH1F("del_R_gen_rec_E_g_55to60","del_R_gen_rec_55to60",100,-0.4,0.4);
    del_R_gen_rec_E_g_55to60->SetLineColor(kBlue);
    del_R_gen_rec_E_W_55to60 = new TH1F("del_R_gen_rec_E_W_55to60","del_R_gen_rec_55to60",100,-0.4,0.4);
    del_R_gen_rec_E_W_55to60->SetLineColor(kGreen);
    del_R_gen_rec_W_g_55to60 = new TH1F("del_R_gen_rec_W_g_55to60","del_R_gen_rec_55to60",100,-0.4,0.4);
    del_R_gen_rec_W_g_55to60->SetLineColor(kRed);
    
    
    
    del_R2_gen_rec_E_g_5to10 = new TH2F("del_R2_gen_rec_E_g_5to10","del_R2_gen_rec_5to10",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_5to10= new TH2F("del_R2_gen_rec_E_W_5to10","del_R2_gen_rec_5to10",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_5to10 = new TH2F("del_R2_gen_rec_W_g_5to10","del_R2_gen_rec_5to10",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_10to15 = new TH2F("del_R2_gen_rec_E_g_10to15","del_R2_gen_rec_10to15",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_10to15 = new TH2F("del_R2_gen_rec_E_W_10to15","del_R2_gen_rec_10to15",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_10to15 = new TH2F("del_R2_gen_rec_W_g_10to15","del_R2_gen_rec_10to15",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_15to20 = new TH2F("del_R2_gen_rec_E_g_15to20","del_R2_gen_rec_15to20",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_15to20 = new TH2F("del_R2_gen_rec_E_W_15to20","del_R2_gen_rec_15to20",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_15to20 = new TH2F("del_R2_gen_rec_W_g_15to20","del_R2_gen_rec_15to20",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_20to25 = new TH2F("del_R2_gen_rec_E_g_20to25","del_R2_gen_rec_20to25",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_20to25 = new TH2F("del_R2_gen_rec_E_W_20to25","del_R2_gen_rec_20to25",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_20to25 = new TH2F("del_R2_gen_rec_W_g_20to25","del_R2_gen_rec_20to25",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_25to30 = new TH2F("del_R2_gen_rec_E_g_25to30","del_R2_gen_rec_25to30",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_25to30 = new TH2F("del_R2_gen_rec_E_W_25to30","del_R2_gen_rec_25to30",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_25to30 = new TH2F("del_R2_gen_rec_W_g_25to30","del_R2_gen_rec_25to30",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_30to35 = new TH2F("del_R2_gen_rec_E_g_30to35","del_R2_gen_rec_30to35",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_30to35 = new TH2F("del_R2_gen_rec_E_W_30to35","del_R2_gen_rec_30to35",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_30to35 = new TH2F("del_R2_gen_rec_W_g_30to35","del_R2_gen_rec_30to35",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_35to40 = new TH2F("del_R2_gen_rec_E_g_35to40","del_R2_gen_rec_35to40",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_35to40 = new TH2F("del_R2_gen_rec_E_W_35to40","del_R2_gen_rec_35to40",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_35to40 = new TH2F("del_R2_gen_rec_W_g_35to40","del_R2_gen_rec_35to40",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_40to45 = new TH2F("del_R2_gen_rec_E_g_40to45","del_R2_gen_rec_40to45",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_40to45 = new TH2F("del_R2_gen_rec_E_W_40to45","del_R2_gen_rec_40to45",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_40to45 = new TH2F("del_R2_gen_rec_W_g_40to45","del_R2_gen_rec_40to45",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_45to50 = new TH2F("del_R2_gen_rec_E_g_45to50","del_R2_gen_rec_45to50",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_45to50 = new TH2F("del_R2_gen_rec_E_W_45to50","del_R2_gen_rec_45to50",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_45to50 = new TH2F("del_R2_gen_rec_W_g_45to50","del_R2_gen_rec_45to50",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_50to55 = new TH2F("del_R2_gen_rec_E_g_50to55","del_R2_gen_rec_50to55",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_50to55 = new TH2F("del_R2_gen_rec_E_W_50to55","del_R2_gen_rec_50to55",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_50to55 = new TH2F("del_R2_gen_rec_W_g_50to55","del_R2_gen_rec_50to55",100,0,0.45,100,0,0.45);
    
    del_R2_gen_rec_E_g_55to60 = new TH2F("del_R2_gen_rec_E_g_55to60","del_R2_gen_rec_55to60",100,0,0.2,100,0,0.2);
    del_R2_gen_rec_E_W_55to60 = new TH2F("del_R2_gen_rec_E_W_55to60","del_R2_gen_rec_55to60",100,0,0.45,100,0,0.45);
    del_R2_gen_rec_W_g_55to60 = new TH2F("del_R2_gen_rec_W_g_55to60","del_R2_gen_rec_55to60",100,0,0.45,100,0,0.45);
   

    


    
      TFile *f;
    f = new TFile("LEP1MC1994_recons_aftercut.root");
   
      
    TTree *tree = (TTree*) f->Get("akR4ESchemeJetTree");
    TTree *tree_g = (TTree*) f->Get("akR4WTAmodpSchemeJetTree");
        TTree *tree_genE = (TTree*) f->Get("akR4ESchemeGenJetTree");
      TTree *tree_genWTA = (TTree*) f->Get("akR4WTAmodpSchemeGenJetTree");
    TTree *tt = (TTree*) f->Get("t");
    
    cout<<"Analyzing "<<tree->GetEntries()<<" events!"<<endl;

    //Create Array Reader
    TTreeReader tr(tree);
    TTreeReader tr_g(tree_g);
    TTreeReader tr_genE(tree_genE);
    TTreeReader tr_genW(tree_genWTA);
    TTreeReader tr_t(tt);
    
    TTreeReaderArray<int>   nref1(tr, "nref");
        TTreeReaderArray<float> jtpt1(tr, "jtpt");
	 TTreeReaderArray<float> jteta1(tr, "jteta");
	  TTreeReaderArray<float> jtphi1(tr, "jtphi");
	   TTreeReaderArray<float> jtm1(tr, "jtm");
	    TTreeReaderArray<int> jtN1(tr, "jtN");
	     TTreeReaderArray<int> jtNPW1(tr, "jtNPW");
	      TTreeReaderArray<float> jtptFracPW1(tr, "jtptFracPW");
	       TTreeReaderArray<float> zgJtPt_Beta0p00ZCut0p101(tr, "zgJtPt_Beta0p00ZCut0p10");
	        TTreeReaderArray<float> zgJtPhi_Beta0p00ZCut0p101(tr, "zgJtPhi_Beta0p00ZCut0p10");
		 TTreeReaderArray<float> zgJtEta_Beta0p00ZCut0p101(tr, "zgJtEta_Beta0p00ZCut0p10");
		 TTreeReaderArray<float> zg_Beta0p00ZCut0p101(tr, "zg_Beta0p00ZCut0p10");
		  TTreeReaderArray<float> rg_Beta0p00ZCut0p101(tr, "rg_Beta0p00ZCut0p10");
       

TTreeReaderArray<int>   nrefg(tr_g, "nref");
        TTreeReaderArray<float> jtptg(tr_g, "jtpt");
         TTreeReaderArray<float> jtetag(tr_g, "jteta");
          TTreeReaderArray<float> jtphig(tr_g, "jtphi");
           TTreeReaderArray<float> jtmg(tr_g, "jtm");
            TTreeReaderArray<int> jtNg(tr_g, "jtN");
             TTreeReaderArray<int> jtNPWg(tr_g, "jtNPW");
              TTreeReaderArray<float> jtptFracPWg(tr_g, "jtptFracPW");
               TTreeReaderArray<float> zgJtPt_Beta0p00ZCut0p10g(tr_g, "zgJtPt_Beta0p00ZCut0p10");
                TTreeReaderArray<float> zgJtPhi_Beta0p00ZCut0p10g(tr_g, "zgJtPhi_Beta0p00ZCut0p10");
                 TTreeReaderArray<float> zgJtEta_Beta0p00ZCut0p10g(tr_g, "zgJtEta_Beta0p00ZCut0p10");
                 TTreeReaderArray<float> zg_Beta0p00ZCut0p10g(tr_g, "zg_Beta0p00ZCut0p10");
                  TTreeReaderArray<float> rg_Beta0p00ZCut0p10g(tr_g, "rg_Beta0p00ZCut0p10");


		   TTreeReaderArray<int>   nref1gen(tr_genE, "nref");
        TTreeReaderArray<float> jtpt1gen(tr_genE, "jtpt");
         TTreeReaderArray<float> jteta1gen(tr_genE, "jteta");
          TTreeReaderArray<float> jtphi1gen(tr_genE, "jtphi");
           TTreeReaderArray<float> jtm1gen(tr_genE, "jtm");
            TTreeReaderArray<int> jtN1gen(tr_genE, "jtN");
             TTreeReaderArray<int> jtNPW1gen(tr_genE, "jtNPW");
              TTreeReaderArray<float> jtptFracPW1gen(tr_genE, "jtptFracPW");
               TTreeReaderArray<float> zgJtPt_Beta0p00ZCut0p101gen(tr_genE, "zgJtPt_Beta0p00ZCut0p10");
                TTreeReaderArray<float> zgJtPhi_Beta0p00ZCut0p101gen(tr_genE, "zgJtPhi_Beta0p00ZCut0p10");
                 TTreeReaderArray<float> zgJtEta_Beta0p00ZCut0p101gen(tr_genE, "zgJtEta_Beta0p00ZCut0p10");
                 TTreeReaderArray<float> zg_Beta0p00ZCut0p101gen(tr_genE, "zg_Beta0p00ZCut0p10");
                  TTreeReaderArray<float> rg_Beta0p00ZCut0p101gen(tr_genE, "rg_Beta0p00ZCut0p10");


TTreeReaderArray<int>   nrefgW(tr_genW, "nref");
        TTreeReaderArray<float> jtptgW(tr_genW, "jtpt");
         TTreeReaderArray<float> jtetagW(tr_genW, "jteta");
          TTreeReaderArray<float> jtphigW(tr_genW, "jtphi");
           TTreeReaderArray<float> jtmgW(tr_genW, "jtm");
            TTreeReaderArray<int> jtNgW(tr_genW, "jtN");
             TTreeReaderArray<int> jtNPWgW(tr_genW, "jtNPW");
              TTreeReaderArray<float> jtptFracPWgW(tr_genW, "jtptFracPW");
               TTreeReaderArray<float> zgJtPt_Beta0p00ZCut0p10gW(tr_genW, "zgJtPt_Beta0p00ZCut0p10");
                TTreeReaderArray<float> zgJtPhi_Beta0p00ZCut0p10gW(tr_genW, "zgJtPhi_Beta0p00ZCut0p10");
                 TTreeReaderArray<float> zgJtEta_Beta0p00ZCut0p10gW(tr_genW, "zgJtEta_Beta0p00ZCut0p10");
                 TTreeReaderArray<float> zg_Beta0p00ZCut0p10gW(tr_genW, "zg_Beta0p00ZCut0p10");
                  TTreeReaderArray<float> rg_Beta0p00ZCut0p10gW(tr_genW, "rg_Beta0p00ZCut0p10");
    
    TTreeReaderArray<float> tSphericity(tr_t, "Sphericity");
    TTreeReaderArray<float> tSTheta(tr_t, "STheta");
    
    TTreeReaderArray<bool> tpassesNTupleAfterCut(tr_t,"passesNTupleAfterCut");
    TTreeReaderArray<bool> tpassesTotalChgEnergyMin(tr_t,"passesTotalChgEnergyMin");
    TTreeReaderArray<bool> tpassesNTrkMin(tr_t,"passesNTrkMin");
    TTreeReaderArray<bool> tpassesMissP(tr_t,"passesMissP");
    TTreeReaderArray<bool> tpassesSTheta(tr_t,"passesSTheta");
    
    int counter(0);
    int NTupleAfterCut(0);
    int TotalChgEnergyMin(0);
    int NTrkMin(0);
    int STheta(0);
    int MissP(0);
    
    int counter1(0);
    int counter2(0);
    int counter3(0);
    int counter4(0);
    int counter5(0);
    int counter6(0);
    int counter7(0);
    int counter8(0);
    int counter9(0);
    int counter10(0);
    int counter11(0);
    int counter12(0);
    int counter13(0);
  
    

    
    
    //Loop over events
    while (tr.Next() && tr_g.Next() && tr_genE.Next()&& tr_genW.Next() && tr_t.Next()) {
        
        //      cout << tSphericity[0]<<endl;
        if(counter%100==0) cout<<"Analyzing event "<<counter<<endl;
        counter++;
        
        if(tpassesNTupleAfterCut[0] == 1) NTupleAfterCut++;
        if(tpassesTotalChgEnergyMin[0] == 1) TotalChgEnergyMin++;
        if (tpassesNTrkMin[0] == 1) NTrkMin++;
        if(tpassesSTheta[0] == 1) STheta++;
        if(tpassesMissP[0] == 1) MissP++;
        
        if(tpassesNTupleAfterCut[0] == 1 && tpassesTotalChgEnergyMin[0] == 1 && tpassesNTrkMin[0] == 1 && tpassesSTheta[0] == 1 && tpassesMissP[0] == 1)
        {counter2++;}
        
        if(tpassesSTheta[0] == 1 && tpassesMissP[0] == 1)
        {counter3++;}
        
        if(tpassesSTheta[0] == 1) {counter4++;}
        else if (tpassesNTupleAfterCut[0] == 1) {counter5++;}
        else if (tpassesTotalChgEnergyMin[0] == 1) {counter6++;}
        else if (tpassesNTrkMin[0] == 1) {counter7++;}
        else if ( tpassesMissP[0] == 1) {counter8++;}
        
        if(tpassesNTupleAfterCut[0] == 1) {
            if ( tpassesTotalChgEnergyMin[0] == 1 ) {
                counter10++;
                if (tpassesNTrkMin[0] == 1) {
                    counter11++;
                    if (tpassesSTheta[0] == 1) {
                        counter12++;
                        if (tpassesMissP[0] == 1){
                            counter13++;
                        }
                    }
                }
            }
        }
        
        
        
        if(tpassesSTheta[0] == 1)
           //tpassesNTupleAfterCut[0] == 1 && tpassesTotalChgEnergyMin[0] == 1 && tpassesNTrkMin[0] == 1 && tpassesSTheta[0] == 1 && tpassesMissP[0] == 1)
           {
            
            hsphericity->Fill(tSphericity[0]);
            htheta->Fill(tSTheta[0]);
            
            //Loop over generated particles
            
            for(int jref=0;jref<jtpt1.GetSize();jref++){
                if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>5 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<10) counter1++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>10 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<15) counter2++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>15 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<20) counter3++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>20 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<25) counter4++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>25 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<30) counter5++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>30 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<35) counter6++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>35 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<40) counter7++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>40 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<45) counter8++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>45 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<50) counter9++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>50 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<55) counter10++;
                else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>55 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<60) counter11++;
                }
            
            for(int jref=0;jref<jtpt1gen.GetSize();jref++){
                if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>5 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<10) counter21++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>10 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<15) counter22++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>15 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<20) counter23++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>20 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<25) counter24++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>25 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<30) counter25++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>30 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<35) counter26++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>35 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<40) counter27++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>40 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<45) counter28++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>45 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<50) counter29++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>50 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<55) counter30++;
                else if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>55 && jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))<60) counter31++;
                }
            
            
            for(int jref=0;jref<jtptg.GetSize();jref++){
                if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>20 ){
                    h1b->Fill(jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))); h2b->Fill(jtphig[jref]); h3b->Fill(2*TMath::ATan(exp(-1*jtetag[jref])));
                    for(int iref=0;iref<jtptgW.GetSize();iref++){
                        //   if (jtptgW[iref]/sin(2*TMath::ATan(exp(-1*jtetagW[iref])))>20){
                        float del_eta = jtetagW[iref]-jtetag[jref];
                        float del_phi = TMath::ACos(cos(jtphigW[iref]-jtphig[jref]));
                        float del_R = sqrt(del_eta*del_eta+del_phi*del_phi);
                        if (del_R<0.4){
                            del_pt_w->Fill(jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))-jtptgW[iref]/sin(2*TMath::ATan(exp(-1*jtetagW[iref]))));
                            del_phi_w->Fill(del_phi);
                            del_eta_w->Fill(del_eta);
                            break;
                        }}
                }}
            
            
            int a=0;
            for(int iref=0;iref<jtpt1.GetSize();iref++){ //jtpt1.GetSize()
                if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>20){
                    h1a->Fill(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref]))));
                    h1c->Fill(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref]))));
                    h2a->Fill(jtphi1[iref]);
                    h2c->Fill(zgJtPhi_Beta0p00ZCut0p101[iref]);
                    h3a->Fill(2*TMath::ATan(exp(-1*jteta1[iref])));
                    h3c->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])));
                    
                    p_vs_theta->Fill((2*TMath::ATan(exp(-1*jteta1[iref]))),jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref]))));
                    
                    float del_eta_E_vs_g = jteta1[iref] - zgJtEta_Beta0p00ZCut0p101[iref];
                    float del_phi_E_vs_g = TMath::ACos(cos(jtphi1[iref] - zgJtPhi_Beta0p00ZCut0p101[iref]));
                    float del_R_E_vs_g = sqrt(del_eta_E_vs_g*del_eta_E_vs_g + del_phi_E_vs_g*del_phi_E_vs_g);
                    if(del_R_E_vs_g<0.4){
                      //  h6->Fill(del_R_E_vs_g);
                    //    h12->Fill(del_eta_E_vs_g);
                 //       h13->Fill(del_phi_E_vs_g);
                        h9->Fill(del_eta_E_vs_g,del_phi_E_vs_g);}
                    
                    
                }}
            
            for(int iref=0;iref<jtpt1.GetSize();iref++){ //jtpt1.GetSize()
                if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>5){
                    float del_eta_E_vs_g = jteta1[iref] - zgJtEta_Beta0p00ZCut0p101[iref];
                    float del_phi_E_vs_g = TMath::ACos(cos(jtphi1[iref] - zgJtPhi_Beta0p00ZCut0p101[iref]));
                    float del_R_E_vs_g = sqrt(del_eta_E_vs_g*del_eta_E_vs_g + del_phi_E_vs_g*del_phi_E_vs_g);
                    if(del_R_E_vs_g<0.4){
                        if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>5 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<10){
                            h6_5to10->Fill(del_R_E_vs_g);
                            h12_5to10->Fill(del_eta_E_vs_g);
                            h13_5to10->Fill(del_phi_E_vs_g);}
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>10 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<15){
                            h12_10to15->Fill(del_eta_E_vs_g);
                            h13_10to15->Fill(del_phi_E_vs_g);
                            h6_10to15->Fill(del_R_E_vs_g);}
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>15 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<20){
                            h12_15to20->Fill(del_eta_E_vs_g);
                            h13_15to20->Fill(del_phi_E_vs_g);
                            h6_15to20->Fill(del_R_E_vs_g);}
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>20 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<25){
                            h12_20to25->Fill(del_eta_E_vs_g);
                            h13_20to25->Fill(del_phi_E_vs_g);
                            h6_20to25->Fill(del_R_E_vs_g);}
                        
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>25 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<30){
                            h12_25to30->Fill(del_eta_E_vs_g);
                            h13_25to30->Fill(del_phi_E_vs_g);
                            h6_25to30->Fill(del_R_E_vs_g);}
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>30 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<35){
                            h12_30to35->Fill(del_eta_E_vs_g);
                            h13_30to35->Fill(del_phi_E_vs_g);
                            h6_30to35->Fill(del_R_E_vs_g);}
                        
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>35 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<40){
                            h12_35to40->Fill(del_eta_E_vs_g);
                            h13_35to40->Fill(del_phi_E_vs_g);
                            h6_35to40->Fill(del_R_E_vs_g);}
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>40 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<45){
                            h12_40to45->Fill(del_eta_E_vs_g);
                            h13_40to45->Fill(del_phi_E_vs_g);
                            h6_40to45->Fill(del_R_E_vs_g);}
                        
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>45 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<50){
                            h12_45to50->Fill(del_eta_E_vs_g);
                            h13_45to50->Fill(del_phi_E_vs_g);
                            h6_45to50->Fill(del_R_E_vs_g);}
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>50 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<55){
                            h12_50to55->Fill(del_eta_E_vs_g);
                            h13_50to55->Fill(del_phi_E_vs_g);
                            h6_50to55->Fill(del_R_E_vs_g);}
                        else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>55 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<60){
                            h12_55to60->Fill(del_eta_E_vs_g);
                            h13_55to60->Fill(del_phi_E_vs_g);
                            h6_55to60->Fill(del_R_E_vs_g);}
                        
                    }}}
            
            for(int iref=0;iref<jtpt1gen.GetSize();iref++){ //jtpt1.GetSize()
                if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>5){
                    float del_eta_E_vs_g = jteta1gen[iref] - zgJtEta_Beta0p00ZCut0p101gen[iref];
                    float del_phi_E_vs_g = TMath::ACos(cos(jtphi1gen[iref] - zgJtPhi_Beta0p00ZCut0p101gen[iref]));
                    float del_R_E_vs_g = sqrt(del_eta_E_vs_g*del_eta_E_vs_g + del_phi_E_vs_g*del_phi_E_vs_g);
                    if(del_R_E_vs_g<0.4){
                        if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>5 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<10){
                            h12b_5to10->Fill(del_eta_E_vs_g);
                            h13b_5to10->Fill(del_phi_E_vs_g);
                            h6b_5to10->Fill(del_R_E_vs_g);}
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>10 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<15){
                            h12b_10to15->Fill(del_eta_E_vs_g);
                            h13b_10to15->Fill(del_phi_E_vs_g);
                            h6b_10to15->Fill(del_R_E_vs_g);}
                        
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>15 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<20){
                            h12b_15to20->Fill(del_eta_E_vs_g);
                            h13b_15to20->Fill(del_phi_E_vs_g);
                            h6b_15to20->Fill(del_R_E_vs_g);}
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>20 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<25){
                            h12b_20to25->Fill(del_eta_E_vs_g);
                            h13b_20to25->Fill(del_phi_E_vs_g);
                            h6b_20to25->Fill(del_R_E_vs_g);}
                        
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>25 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<30){
                            h12b_25to30->Fill(del_eta_E_vs_g);
                            h13b_25to30->Fill(del_phi_E_vs_g);
                            h6b_25to30->Fill(del_R_E_vs_g);}
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>30 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<35){
                            h12b_30to35->Fill(del_eta_E_vs_g);
                            h13b_30to35->Fill(del_phi_E_vs_g);
                            h6b_30to35->Fill(del_R_E_vs_g);
                        }
                        
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>35 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<40){
                            h12b_35to40->Fill(del_eta_E_vs_g);
                            h13b_35to40->Fill(del_phi_E_vs_g);
                            h6b_35to40->Fill(del_R_E_vs_g);}
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>40 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<45){
                            h12b_40to45->Fill(del_eta_E_vs_g);
                            h13b_40to45->Fill(del_phi_E_vs_g);
                            h6b_40to45->Fill(del_R_E_vs_g);
                        }
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>45 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<50){
                            h12b_45to50->Fill(del_eta_E_vs_g);
                            h13b_45to50->Fill(del_phi_E_vs_g);
                            h6b_45to50->Fill(del_R_E_vs_g);}
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>50 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<55){
                            h12b_50to55->Fill(del_eta_E_vs_g);
                            h13b_50to55->Fill(del_phi_E_vs_g);
                            h6b_50to55->Fill(del_R_E_vs_g);}
                        else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>55 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<60){
                            h12b_55to60->Fill(del_eta_E_vs_g);
                            h13b_55to60->Fill(del_phi_E_vs_g);
                            h6b_55to60->Fill(del_R_E_vs_g);}
                        
                    }}}
            
            
            
            for(int iref=0;iref<jtpt1.GetSize();iref++){
                if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>5){
                    for(int jref=0;jref<jtptg.GetSize();jref++){
                        float del_eta_E_vs_wta = jteta1[iref] - jtetag[jref];
                        float  del_phi_E_vs_wta = TMath::ACos(cos(jtphi1[iref] - jtphig[jref]));
                        float del_R_E_vs_wta = sqrt(del_eta_E_vs_wta*del_eta_E_vs_wta +  del_phi_E_vs_wta * del_phi_E_vs_wta);
                        if (del_R_E_vs_wta < 0.4){
                            if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>5 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<10){
                                h14_5to10->Fill(del_eta_E_vs_wta);
                                h15_5to10->Fill(del_phi_E_vs_wta);
                                h7_5to10->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>10 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<15){
                                h14_10to15->Fill(del_eta_E_vs_wta);
                                h15_10to15->Fill(del_phi_E_vs_wta);
                                h7_10to15->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>15 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<20){
                                h14_15to20->Fill(del_eta_E_vs_wta);
                                h15_15to20->Fill(del_phi_E_vs_wta);
                                h7_15to20->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>20 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<25){
                                h14_20to25->Fill(del_eta_E_vs_wta);
                                h15_20to25->Fill(del_phi_E_vs_wta);
                                h7_20to25->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>25 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<30){
                                h14_25to30->Fill(del_eta_E_vs_wta);
                                h15_25to30->Fill(del_phi_E_vs_wta);
                                h7_25to30->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>30 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<35){
                                h14_30to35->Fill(del_eta_E_vs_wta);
                                h15_30to35->Fill(del_phi_E_vs_wta);
                                h7_30to35->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>35 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<40){
                                h14_35to40->Fill(del_eta_E_vs_wta);
                                h15_35to40->Fill(del_phi_E_vs_wta);
                                h7_35to40->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>40 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<45){
                                h14_40to45->Fill(del_eta_E_vs_wta);
                                h15_40to45->Fill(del_phi_E_vs_wta);
                                h7_40to45->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>45 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<50){
                                h14_45to50->Fill(del_eta_E_vs_wta);
                                h15_45to50->Fill(del_phi_E_vs_wta);
                                h7_45to50->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>50 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<55){
                                h14_50to55->Fill(del_eta_E_vs_wta);
                                h15_50to55->Fill(del_phi_E_vs_wta);
                                h7_50to55->Fill(del_R_E_vs_wta);}
                            else if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>55 && jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))<60){
                                h14_55to60->Fill(del_eta_E_vs_wta);
                                h15_55to60->Fill(del_phi_E_vs_wta);
                                h7_55to60->Fill(del_R_E_vs_wta);}
                            break;
                            
                        }}}}
            
            for(int iref=0;iref<zgJtPt_Beta0p00ZCut0p101.GetSize();iref++){
                if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>5){
                    for(int jref=0;jref<jtptg.GetSize();jref++){
                        //      if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>20){
                        auto del_eta_g_vs_wta = zgJtEta_Beta0p00ZCut0p101[iref] - jtetag[jref];
                        auto del_phi_g_vs_wta = TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101[iref] -  jtphig[jref]));
                        auto del_R_g_vs_wta = sqrt(del_eta_g_vs_wta*del_eta_g_vs_wta + del_phi_g_vs_wta*del_phi_g_vs_wta);
                        if(del_R_g_vs_wta <0.4){
                            if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>5 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<10)){
                                h16_5to10->Fill(del_eta_g_vs_wta);
                                h17_5to10->Fill(del_phi_g_vs_wta);
                                h8_5to10->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>10 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<15)){
                                h16_10to15->Fill(del_eta_g_vs_wta);
                                h17_10to15->Fill(del_phi_g_vs_wta);
                                h8_10to15->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>15 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<20)){
                                h16_15to20->Fill(del_eta_g_vs_wta);
                                h17_15to20->Fill(del_phi_g_vs_wta);
                                h8_15to20->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>20 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<25)){
                                h16_20to25->Fill(del_eta_g_vs_wta);
                                h17_20to25->Fill(del_phi_g_vs_wta);
                                h8_20to25->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>25 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<30)){
                                h16_25to30->Fill(del_eta_g_vs_wta);
                                h17_25to30->Fill(del_phi_g_vs_wta);
                                h8_25to30->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>30 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<35)){
                                h16_30to35->Fill(del_eta_g_vs_wta);
                                h17_30to35->Fill(del_phi_g_vs_wta);
                                h8_30to35->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>35 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<40)){
                                h16_35to40->Fill(del_eta_g_vs_wta);
                                h17_35to40->Fill(del_phi_g_vs_wta);
                                h8_35to40->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>40 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<45)){
                                h16_40to45->Fill(del_eta_g_vs_wta);
                                h17_40to45->Fill(del_phi_g_vs_wta);
                                h8_40to45->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>45 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<50)){
                                h16_45to50->Fill(del_eta_g_vs_wta);
                                h17_45to50->Fill(del_phi_g_vs_wta);
                                h8_45to50->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>50 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<55)){
                                h16_50to55->Fill(del_eta_g_vs_wta);
                                h17_50to55->Fill(del_phi_g_vs_wta);
                                h8_50to55->Fill(del_R_g_vs_wta);}
                            else if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>55 &&  (zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))<60)){
                                h16_55to60->Fill(del_eta_g_vs_wta);
                                h17_55to60->Fill(del_phi_g_vs_wta);
                                h8_55to60->Fill(del_R_g_vs_wta);}
                            break;
                        }
                        
                    }}}
            
            for(int iref=0;iref<jtpt1gen.GetSize();iref++){
                if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>5){
                    for(int jref=0;jref<jtptgW.GetSize();jref++){
                        float del_eta_E_vs_wta = jteta1gen[iref] - jtetagW[jref];
                        float  del_phi_E_vs_wta = TMath::ACos(cos(jtphi1gen[iref] - jtphigW[jref]));
                        float del_R_E_vs_wta = sqrt(del_eta_E_vs_wta*del_eta_E_vs_wta +  del_phi_E_vs_wta * del_phi_E_vs_wta);
                        if (del_R_E_vs_wta < 0.4) {
                            if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>5 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<10){
                                h14b_5to10->Fill(del_eta_E_vs_wta);
                                h15b_5to10->Fill(del_phi_E_vs_wta);
                                h7b_5to10->Fill(del_R_E_vs_wta);}
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>10 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<15){
                                h14b_10to15->Fill(del_eta_E_vs_wta);
                                h15b_10to15->Fill(del_phi_E_vs_wta);
                                h7b_10to15->Fill(del_R_E_vs_wta);}
                            
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>15 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<20){
                                h14b_15to20->Fill(del_eta_E_vs_wta);
                                h15b_15to20->Fill(del_phi_E_vs_wta);
                                h7b_15to20->Fill(del_R_E_vs_wta);}
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>20 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<25){
                                h14b_20to25->Fill(del_eta_E_vs_wta);
                                h15b_20to25->Fill(del_phi_E_vs_wta);
                                h7b_20to25->Fill(del_R_E_vs_wta);}
                            
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>25 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<30){
                                h14b_25to30->Fill(del_eta_E_vs_wta);
                                h15b_25to30->Fill(del_phi_E_vs_wta);
                                h7b_25to30->Fill(del_R_E_vs_wta);}
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>30 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<35){
                                h14b_30to35->Fill(del_eta_E_vs_wta);
                                h15b_30to35->Fill(del_phi_E_vs_wta);
                                h7b_30to35->Fill(del_R_E_vs_wta);}
                            
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>35 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<40){
                                h14b_35to40->Fill(del_eta_E_vs_wta);
                                h15b_35to40->Fill(del_phi_E_vs_wta);
                                h7b_35to40->Fill(del_R_E_vs_wta);}
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>40 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<45){
                                h14b_40to45->Fill(del_eta_E_vs_wta);
                                h15b_40to45->Fill(del_phi_E_vs_wta);
                                h7b_40to45->Fill(del_R_E_vs_wta);}
                            
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>45 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<50){
                                h14b_45to50->Fill(del_eta_E_vs_wta);
                                h15b_45to50->Fill(del_phi_E_vs_wta);
                                h7b_45to50->Fill(del_R_E_vs_wta);}
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>50 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<55){
                                h14b_50to55->Fill(del_eta_E_vs_wta);
                                h15b_50to55->Fill(del_phi_E_vs_wta);
                                h7b_50to55->Fill(del_R_E_vs_wta);}
                            else if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>55 && jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))<60){
                                h14b_55to60->Fill(del_eta_E_vs_wta);
                                h15b_55to60->Fill(del_phi_E_vs_wta);
                                h7b_55to60->Fill(del_R_E_vs_wta);}
                            
                            break;
                            //   h14b->Fill(del_eta_E_vs_wta);
                            //    h15b->Fill(del_phi_E_vs_wta);
                        }}}}
                        
            for(int iref=0;iref<zgJtPt_Beta0p00ZCut0p101.GetSize();iref++){
                if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>5){
                    for(int jref=0;jref<jtptg.GetSize();jref++){
                        auto del_eta_g_vs_wta = zgJtEta_Beta0p00ZCut0p101gen[iref] - jtetagW[jref];
                        auto del_phi_g_vs_wta = TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101gen[iref] -  jtphigW[jref]));
                        auto del_R_g_vs_wta = sqrt(del_eta_g_vs_wta*del_eta_g_vs_wta + del_phi_g_vs_wta*del_phi_g_vs_wta);
                        
                        if(del_R_g_vs_wta <0.4){
                            if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>5 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<10)){
                                h16b_5to10->Fill(del_eta_g_vs_wta);
                                h17b_5to10->Fill(del_phi_g_vs_wta);
                                h8b_5to10->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>10 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<15)){
                                h16b_10to15->Fill(del_eta_g_vs_wta);
                                h17b_10to15->Fill(del_phi_g_vs_wta);
                                h8b_10to15->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>15 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<20)){
                                h16b_15to20->Fill(del_eta_g_vs_wta);
                                h17b_15to20->Fill(del_phi_g_vs_wta);
                                h8b_15to20->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>20 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<25)){
                                h16b_20to25->Fill(del_eta_g_vs_wta);
                                h17b_20to25->Fill(del_phi_g_vs_wta);
                                h8b_20to25->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>25 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<30)){
                                h16b_25to30->Fill(del_eta_g_vs_wta);
                                h17b_25to30->Fill(del_phi_g_vs_wta);
                                h8b_25to30->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>30 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<35)){
                                h16b_30to35->Fill(del_eta_g_vs_wta);
                                h17b_30to35->Fill(del_phi_g_vs_wta);
                                h8b_30to35->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>35 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<40)){
                                h16b_35to40->Fill(del_eta_g_vs_wta);
                                h17b_35to40->Fill(del_phi_g_vs_wta);
                                h8b_35to40->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>40 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<45)){
                                h16b_40to45->Fill(del_eta_g_vs_wta);
                                h17b_40to45->Fill(del_phi_g_vs_wta);
                                h8b_40to45->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>45 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<50)){
                                h16b_45to50->Fill(del_eta_g_vs_wta);
                                h17b_45to50->Fill(del_phi_g_vs_wta);
                                h8b_45to50->Fill(del_R_g_vs_wta);}
                            
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>50 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<55)){
                                h16b_50to55->Fill(del_eta_g_vs_wta);
                                h17b_50to55->Fill(del_phi_g_vs_wta);
                                h8b_50to55->Fill(del_R_g_vs_wta);}
                            else if(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))>55 &&  (zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])))<60)){
                                h16b_55to60->Fill(del_eta_g_vs_wta);
                                h17b_55to60->Fill(del_phi_g_vs_wta);
                                h8b_55to60->Fill(del_R_g_vs_wta);}
                            
                            break;
                        }
                        
                    }}}
                        
                      
            
            
            for(int iref=0;iref<jtpt1.GetSize();iref++){
                if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>20){
                    for(int jref=0;jref<jtpt1gen.GetSize();jref++){
                       // if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>20){
                            float del_eta = jteta1[iref]-jteta1gen[jref];
                            float del_phi = TMath::ACos(cos(jtphi1[iref]-jtphi1gen[jref]));
                            float del_R = sqrt(del_eta*del_eta+del_phi*del_phi);
                            if (del_R<0.4){
                                del_pt_E->Fill(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))-jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref]))));
                                del_phi_E->Fill(del_phi);
                                del_eta_E->Fill(del_eta);
                                break;
                            }}}}
            
            for(int iref=0;iref<jtpt1.GetSize();iref++){
                if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>20){
                    for(int jref=0;jref<zgJtPt_Beta0p00ZCut0p101gen.GetSize();jref++){
                   //     if (zgJtPt_Beta0p00ZCut0p101gen[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[jref])))>20){
                            float del_eta = jteta1[iref]-zgJtEta_Beta0p00ZCut0p101gen[jref];
                            float del_phi = TMath::ACos(cos(jtphi1[iref]-zgJtPhi_Beta0p00ZCut0p101gen[jref]));
                            float del_R = sqrt(del_eta*del_eta+del_phi*del_phi);
                            if (del_R<0.4){
                                del_pt_g->Fill(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))-zgJtPt_Beta0p00ZCut0p101gen[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[jref]))));
                                del_phi_g->Fill(del_phi);
                                del_eta_g->Fill(del_eta);
                                break;
                            }}}}
            
            for(int iref=0;iref<jtpt1.GetSize();iref++){
                if(jtpt1[iref]/sin(2*TMath::ATan(exp(-1*jteta1[iref])))>20){
                    for(int jref=0;jref<jtptg.GetSize();jref++){
                      //  if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>20){
                            float del_eta_E_vs_wta = jteta1[iref] - jtetag[jref];
                            float  del_phi_E_vs_wta = TMath::ACos(cos(jtphi1[iref] - jtphig[jref]));
                            float del_R_E_vs_wta = sqrt(del_eta_E_vs_wta*del_eta_E_vs_wta +  del_phi_E_vs_wta * del_phi_E_vs_wta);
                            if (del_R_E_vs_wta < 0.4){
                             //   h7->Fill(del_R_E_vs_wta);
                              //  h14->Fill(del_eta_E_vs_wta);
                              //  h15->Fill(del_phi_E_vs_wta);
                                h10->Fill(del_eta_E_vs_wta, del_phi_E_vs_wta);
                                break;
                            }}}}
            
            
            for(int iref=0;iref<zgJtPt_Beta0p00ZCut0p101.GetSize();iref++){
                if(zgJtPt_Beta0p00ZCut0p101[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[iref])))>20){
                    for(int jref=0;jref<jtptg.GetSize();jref++){
                  //      if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>20){
                            auto del_eta_g_vs_wta = zgJtEta_Beta0p00ZCut0p101[iref] - jtetag[jref];
                            auto del_phi_g_vs_wta = TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101[iref] -  jtphig[jref]));
                            auto del_R_g_vs_wta = sqrt(del_eta_g_vs_wta*del_eta_g_vs_wta + del_phi_g_vs_wta*del_phi_g_vs_wta);
                            if(del_R_g_vs_wta <0.4){
                               // h8->Fill(del_R_g_vs_wta);
                                h11->Fill(del_eta_g_vs_wta,del_phi_g_vs_wta);
                              //  h16->Fill(del_eta_g_vs_wta);
                             //   h17->Fill(del_phi_g_vs_wta);
                                break;
                            }}}}
            
            
            for(int iref=0;iref<jtpt1gen.GetSize();iref++){
                if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>20){
                    
                    h1d->Fill(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref]))));
                    h1f->Fill(zgJtPt_Beta0p00ZCut0p101gen[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref]))));
                    h2d->Fill(jtphi1gen[iref]);
                    h2f->Fill(zgJtPhi_Beta0p00ZCut0p101gen[iref]);
                    h3d->Fill(2*TMath::ATan(exp(-1*jteta1gen[iref])));
                    h3f->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[iref])));
                          
                    float del_eta_E_vs_g = jteta1gen[iref] - zgJtEta_Beta0p00ZCut0p101gen[iref];
                  //  h12b->Fill(del_eta_E_vs_g);
                    float del_phi_E_vs_g = TMath::ACos(cos(jtphi1gen[iref] - zgJtPhi_Beta0p00ZCut0p101gen[iref]));
                  //  h13b->Fill(del_phi_E_vs_g);
                    float del_R_E_vs_g = sqrt(del_eta_E_vs_g*del_eta_E_vs_g + del_phi_E_vs_g*del_phi_E_vs_g);
                    if (del_R_E_vs_g<0.4){
                    //    h6b->Fill(del_R_E_vs_g);
                        h9b->Fill(del_eta_E_vs_g,del_phi_E_vs_g);}
                    
                }}
            
            for(int iref=0;iref<jtpt1gen.GetSize();iref++){
                if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>20){
                    for(int jref=0;jref<jtptgW.GetSize();jref++){
                        // if (jtptgW[jref]/sin(2*TMath::ATan(exp(-1*jtetagW[jref])))>20){
                        float del_eta_E_vs_wta = jteta1gen[iref] - jtetagW[jref];
                        float  del_phi_E_vs_wta = TMath::ACos(cos(jtphi1gen[iref] - jtphigW[jref]));
                        float del_R_E_vs_wta = sqrt(del_eta_E_vs_wta*del_eta_E_vs_wta +  del_phi_E_vs_wta * del_phi_E_vs_wta);
                        if (del_R_E_vs_wta < 0.4) {
                            h10b->Fill(del_eta_E_vs_wta, del_phi_E_vs_wta);
                            break;
                        }}}}
                        
            for(int iref=0;iref<jtpt1gen.GetSize();iref++){
                if(jtpt1gen[iref]/sin(2*TMath::ATan(exp(-1*jteta1gen[iref])))>20){
                    for(int jref=0;jref<jtptgW.GetSize();jref++){
                        auto del_eta_g_vs_wta = zgJtEta_Beta0p00ZCut0p101gen[iref] - jtetagW[jref];
                        auto del_phi_g_vs_wta = TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101gen[iref] -  jtphigW[jref]));
                    auto del_R_g_vs_wta = sqrt(del_eta_g_vs_wta*del_eta_g_vs_wta + del_phi_g_vs_wta*del_phi_g_vs_wta);
                        if(del_R_g_vs_wta <0.4){
                            h11b->Fill(del_eta_g_vs_wta,del_phi_g_vs_wta);
                        }}}}
            
            for(int jref=0;jref<jtptgW.GetSize();jref++){
                if (jtptgW[jref]/sin(2*TMath::ATan(exp(-1*jtetagW[jref])))>20){
                    h1e->Fill(jtptgW[jref]/sin(2*TMath::ATan(exp(-1*jtetagW[jref]))));
                    h3e->Fill(2*TMath::ATan(exp(-1*jtetagW[jref])));
                    h2e->Fill(jtphigW[jref]);
                }}
            
               
               for(int jref=0;jref<jtpt1.GetSize();jref++){
                   if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>5){
                       for(int kref=0;kref<jtpt1gen.GetSize();kref++){
                           float del_eta_rec_gen_e=jteta1[jref]-jteta1gen[kref];
                           float del_phi_rec_gen_e =TMath::ACos(cos(jtphi1[jref]-jtphi1gen[kref]));
                           float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                           if (R_rec_gen_e < 0.4){
                               hz_rec_gen->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                           }}}}
               
               for(int jref=0;jref<zgJtPt_Beta0p00ZCut0p101.GetSize();jref++){
                   if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>5){
                       for(int kref=0;kref<zgJtPt_Beta0p00ZCut0p101gen.GetSize();kref++){
                           float del_eta_rec_gen_e=zgJtEta_Beta0p00ZCut0p101[jref]-zgJtEta_Beta0p00ZCut0p101gen[kref];
                           float del_phi_rec_gen_e =TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101[jref]-zgJtPhi_Beta0p00ZCut0p101gen[kref]));
                           float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                           if (R_rec_gen_e < 0.4){
                               hzg_rec_gen->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                           }}}}
               
               for(int jref=0;jref<jtptg.GetSize();jref++){
                   if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>5){
                       for(int kref=0;kref<jtptgW.GetSize();kref++){
                           float del_eta_rec_gen_e=jtetag[jref]-jtetagW[kref];
                           float del_phi_rec_gen_e =TMath::ACos(cos(jtphig[jref]-jtphigW[kref]));
                           float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                           if (R_rec_gen_e < 0.4){
                               hzw_rec_gen->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                           }}}}
                               
               
               for(int jref=0;jref<jtpt1gen.GetSize();jref++){
                   if (jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref])))>5){
                       for(int kref=0;kref<jtpt1.GetSize();kref++){
                           float del_eta_rec_gen_e=jteta1gen[jref]-jteta1[kref];
                           float del_phi_rec_gen_e =TMath::ACos(cos(jtphi1gen[jref]-jtphi1[kref]));
                           float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                           if (R_rec_gen_e < 0.4){
                               hza_rec_gen->Fill(jtpt1gen[jref]/sin(2*TMath::ATan(exp(-1*jteta1gen[jref]))),jtpt1[kref]/sin(2*TMath::ATan(exp(-1*jteta1[kref]))));
                           }}}}
               
               for(int jref=0;jref<zgJtPt_Beta0p00ZCut0p101gen.GetSize();jref++){
                   if (zgJtPt_Beta0p00ZCut0p101gen[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[jref])))>5){
                       for(int kref=0;kref<zgJtPt_Beta0p00ZCut0p101.GetSize();kref++){
                           float del_eta_rec_gen_e=zgJtEta_Beta0p00ZCut0p101gen[jref]-zgJtEta_Beta0p00ZCut0p101[kref];
                           float del_phi_rec_gen_e =TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101gen[jref]-zgJtPhi_Beta0p00ZCut0p101[kref]));
                           float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                           if (R_rec_gen_e < 0.4){
                               hzag_rec_gen->Fill(zgJtPt_Beta0p00ZCut0p101gen[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[jref]))),zgJtPt_Beta0p00ZCut0p101[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[kref]))));
                           }}}}
               
               for(int jref=0;jref<jtptgW.GetSize();jref++){
                   if (jtptgW[jref]/sin(2*TMath::ATan(exp(-1*jtetagW[jref])))>5){
                       for(int kref=0;kref<jtptg.GetSize();kref++){
                           float del_eta_rec_gen_e=jtetagW[jref]-jtetag[kref];
                           float del_phi_rec_gen_e =TMath::ACos(cos(jtphigW[jref]-jtphig[kref]));
                           float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                           if (R_rec_gen_e < 0.4){
                               hzaw_rec_gen->Fill(jtptgW[jref]/sin(2*TMath::ATan(exp(-1*jtetagW[jref]))),jtptg[kref]/sin(2*TMath::ATan(exp(-1*jtetag[kref]))));
                           }}}}
                               
                               
                           
                           
            //rec vs gen matrix
            for(int jref=0;jref<jtpt1.GetSize();jref++){
                if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>5){
                    for(int kref=0;kref<jtpt1gen.GetSize();kref++){
                        float del_eta_rec_gen_e=jteta1[jref]-jteta1gen[kref];
                        float del_phi_rec_gen_e =TMath::ACos(cos(jtphi1[jref]-jtphi1gen[kref]));
                        float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                        if (R_rec_gen_e < 0.4){
                            if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>5 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<10 &&
                                jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>5 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<10)
                            {h1z_5to10->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_5to10->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_5to10->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref])));
                            }
                            else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>10 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<15 &&
                                     jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>10 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<15 )
                            {h1z_10to15->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_10to15->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_10to15->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>15 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<20 &&
                                     jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>15 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<20)
                            {h1z_15to20->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_15to20->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_15to20->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>20 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<25 &&
                                     jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>20 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<25)
                            {h1z_20to25->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_20to25->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_20to25->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>25 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<30 &&
                                      jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>25 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<30)
                            {h1z_25to30->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_25to30->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_25to30->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>30 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<35 &&
                                      jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>30 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<35)
                            {h1z_30to35->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_30to35->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_30to35->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>35 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<40 &&
                                     jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>35 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<40)
                            {h1z_35to40->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_35to40->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_35to40->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>40 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<45 &&
                                      jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>40 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<45)
                            {h1z_40to45->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_40to45->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_40to45->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>45 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<50 &&
                                     jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>45 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<50)
                            {h1z_45to50->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_45to50->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_45to50->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>50 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<55 &&
                                     jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>50 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<55)
                            {h1z_50to55->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_50to55->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_50to55->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>55 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<60 &&
                                     jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>55 && jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))<60) 
                            {h1z_55to60->Fill(jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref]))),jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref]))));
                                h2z_55to60->Fill(jtphi1gen[kref],jtphi1[jref]);
                                h3z_55to60->Fill(2*TMath::ATan(exp(-1*jteta1gen[kref])),2*TMath::ATan(exp(-1*jteta1[jref]))); }
                            break;}
                    }}}
                            
            for(int jref=0;jref<zgJtPt_Beta0p00ZCut0p101.GetSize();jref++){
                if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>5){
                    for(int kref=0;kref<zgJtPt_Beta0p00ZCut0p101gen.GetSize();kref++){
                        float del_eta_rec_gen_e=zgJtEta_Beta0p00ZCut0p101[jref]-zgJtEta_Beta0p00ZCut0p101gen[kref];
                        float del_phi_rec_gen_e =TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101[jref]-zgJtPhi_Beta0p00ZCut0p101gen[kref]));
                        float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                        if (R_rec_gen_e < 0.4){
                            if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>5 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<10 &&
                                zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>5 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<10)
                            {h1zg_5to10->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_5to10->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_5to10->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])));
                            }
                            else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>10 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<15 &&
                                     zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>10 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<15 )
                            {h1zg_10to15->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_10to15->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_10to15->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>15 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<20 &&
                                     zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>15 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<20)
                            {h1zg_15to20->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_15to20->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_15to20->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>20 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<25 &&
                                     zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>20 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<25)
                            {h1zg_20to25->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_20to25->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_20to25->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else  if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>25 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<30 &&
                                      zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>25 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<30)
                            {h1zg_25to30->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_25to30->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_25to30->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else  if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>30 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<35 &&
                                      zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>30 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<35)
                            {h1zg_30to35->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_30to35->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_30to35->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>35 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<40 &&
                                     zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>35 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<40)
                            {h1zg_35to40->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_35to40->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_35to40->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else  if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>40 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<45 &&
                                      zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>40 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<45)
                            {h1zg_40to45->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_40to45->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_40to45->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>45 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<50 &&
                                     zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>45 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<50)
                            {h1zg_45to50->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_45to50->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_45to50->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>50 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<55 &&
                                     zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>50 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<55)
                            {h1zg_50to55->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_50to55->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_50to55->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>55 && zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<60 &&
                                     zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>55 && zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))<60)
                            {h1zg_55to60->Fill(zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref]))),zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))));
                                h2zg_55to60->Fill(zgJtPhi_Beta0p00ZCut0p101gen[kref],zgJtPhi_Beta0p00ZCut0p101[jref]);
                                h3zg_55to60->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])),2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref]))); }
                            break;}
                    }}}
                    
            for(int jref=0;jref<jtptg.GetSize();jref++){
                if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>5){
                    for(int kref=0;kref<jtptgW.GetSize();kref++){
                        float del_eta_rec_gen_e=jtetag[jref]-jtetagW[kref];
                        float del_phi_rec_gen_e =TMath::ACos(cos(jtphig[jref]-jtphigW[kref]));
                        float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                        if (R_rec_gen_e < 0.4){
                            if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>5 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<10 &&
                                jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>5 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<10)
                            {h1zw_5to10->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_5to10->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_5to10->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref])));
                            }
                            else if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>10 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<15 &&
                                     jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>10 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<15 )
                            {h1zw_10to15->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_10to15->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_10to15->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>15 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<20 &&
                                     jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>15 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<20)
                            {h1zw_15to20->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_15to20->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_15to20->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>20 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<25 &&
                                     jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>20 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<25)
                            {h1zw_20to25->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_20to25->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_20to25->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else  if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>25 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<30 &&
                                      jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>25 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<30)
                            {h1zw_25to30->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_25to30->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_25to30->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else  if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>30 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<35 &&
                                      jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>30 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<35)
                            {h1zw_30to35->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_30to35->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_30to35->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>35 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<40 &&
                                     jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>35 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<40)
                            {h1zw_35to40->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_35to40->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_35to40->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else  if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>40 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<45 &&
                                      jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>40 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<45)
                            {h1zw_40to45->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_40to45->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_40to45->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>45 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<50 &&
                                     jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>45 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<50)
                            {h1zw_45to50->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_45to50->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_45to50->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>50 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<55 &&
                                     jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>50 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<55)
                            {h1zw_50to55->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_50to55->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_50to55->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            else if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>55 && jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))<60 &&
                                     jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))>55 && jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref])))<60)
                            {h1zw_55to60->Fill(jtptgW[kref]/sin(2*TMath::ATan(exp(-1*jtetagW[kref]))),jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref]))));
                                h2zw_55to60->Fill(jtphigW[kref],jtphig[jref]);
                                h3zw_55to60->Fill(2*TMath::ATan(exp(-1*jtetagW[kref])),2*TMath::ATan(exp(-1*jtetag[jref]))); }
                            break;}
                    }}}
                
               //del R rec vs gen
            for(int jref=0;jref<jtpt1.GetSize();jref++){
                float diff_R_rec_e_g = 0; float diff_R_gen_e_g = 0;
                if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>5){
                    for(int iref=0;iref<zgJtPt_Beta0p00ZCut0p101.GetSize();iref++){
                        float del_eta_rec_e_g =jteta1[jref]-zgJtEta_Beta0p00ZCut0p101[iref];
                        float del_phi_rec_e_g =TMath::ACos(cos(jtphi1[jref]-zgJtPhi_Beta0p00ZCut0p101[iref]));
                        float R_rec_e_g = sqrt(del_eta_rec_e_g*del_eta_rec_e_g + del_phi_rec_e_g*del_phi_rec_e_g);
                        if (R_rec_e_g < 0.4){ diff_R_rec_e_g = R_rec_e_g ;
                            break;}//break;
                    }
                    for(int kref=0;kref<jtpt1gen.GetSize();kref++){
                        float del_eta_rec_gen_e=jteta1[jref]-jteta1gen[kref];
                        float del_phi_rec_gen_e =TMath::ACos(cos(jtphi1[jref]-jtphi1gen[kref]));
                        float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                        if (R_rec_gen_e < 0.4){
                            for(int lref=0;lref<zgJtPt_Beta0p00ZCut0p101gen.GetSize();lref++){
                                float del_eta_gen_e_g =jteta1gen[kref]-zgJtEta_Beta0p00ZCut0p101gen[lref];
                                float del_phi_gen_e_g =TMath::ACos(cos(jtphi1gen[kref]-zgJtPhi_Beta0p00ZCut0p101gen[lref]));
                                float R_gen_e_g = sqrt(del_eta_gen_e_g*del_eta_gen_e_g + del_phi_gen_e_g*del_phi_gen_e_g);
                                if (R_gen_e_g < 0.4){ diff_R_gen_e_g = R_gen_e_g ;
                                    if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>5 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<10)
                                    {del_R_gen_rec_E_g_5to10->Fill(diff_R_rec_e_g-diff_R_gen_e_g); 
                                    del_R2_gen_rec_E_g_5to10->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>10 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<15)
                                    {del_R_gen_rec_E_g_10to15->Fill(diff_R_rec_e_g-diff_R_gen_e_g); 
                                        del_R2_gen_rec_E_g_10to15->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>15 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<20)
                                    {del_R_gen_rec_E_g_15to20->Fill(diff_R_rec_e_g-diff_R_gen_e_g);
                                        del_R2_gen_rec_E_g_15to20->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>20 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<25)
                                    {del_R_gen_rec_E_g_20to25->Fill(diff_R_rec_e_g-diff_R_gen_e_g);
                                        del_R2_gen_rec_E_g_20to25->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>25 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<30)
                                    {del_R_gen_rec_E_g_25to30->Fill(diff_R_rec_e_g-diff_R_gen_e_g);
                                        del_R2_gen_rec_E_g_25to30->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>30 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<35)
                                    {del_R_gen_rec_E_g_30to35->Fill(diff_R_rec_e_g-diff_R_gen_e_g);
                                        del_R2_gen_rec_E_g_30to35->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>35 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<40)
                                    {del_R_gen_rec_E_g_35to40->Fill(diff_R_rec_e_g-diff_R_gen_e_g);
                                        del_R2_gen_rec_E_g_35to40->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>40 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<45)
                                    {del_R_gen_rec_E_g_40to45->Fill(diff_R_rec_e_g-diff_R_gen_e_g); 
                                        del_R2_gen_rec_E_g_40to45->Fill(diff_R_gen_e_g,diff_R_rec_e_g); }
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>45 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<50)
                                    {del_R_gen_rec_E_g_45to50->Fill(diff_R_rec_e_g-diff_R_gen_e_g); 
                                        del_R2_gen_rec_E_g_45to50->Fill(diff_R_gen_e_g,diff_R_rec_e_g); }
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>50 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<55)
                                    {del_R_gen_rec_E_g_50to55->Fill(diff_R_rec_e_g-diff_R_gen_e_g);
                                        del_R2_gen_rec_E_g_50to55->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>55 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<60)
                                    {del_R_gen_rec_E_g_55to60->Fill(diff_R_rec_e_g-diff_R_gen_e_g);
                                        del_R2_gen_rec_E_g_55to60->Fill(diff_R_gen_e_g,diff_R_rec_e_g);}
                                    break;}
                                }
                            break;
                        }}}}
 
            
            
            
            for(int jref=0;jref<jtpt1.GetSize();jref++){
                float diff_R_rec_e_w = 0; float diff_R_gen_e_w = 0;
                if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>5){
                    for(int iref=0;iref<jtptg.GetSize();iref++){
                        // if (jtptg[iref]/sin(2*TMath::ATan(exp(-1*jtetag[iref])))>20){
                        float del_eta_rec_e_w =jteta1[jref]-jtetag[iref];
                        float del_phi_rec_e_w =TMath::ACos(cos(jtphi1[jref]-jtphig[iref]));
                        float R_rec_e_w = sqrt(del_eta_rec_e_w*del_eta_rec_e_w + del_phi_rec_e_w*del_phi_rec_e_w);
                        if (R_rec_e_w < 0.4){ diff_R_rec_e_w = R_rec_e_w ; break; }
                    }
                    for(int kref=0;kref<jtpt1gen.GetSize();kref++){
                        //  if (jtpt1gen[kref]/sin(2*TMath::ATan(exp(-1*jteta1gen[kref])))>20){
                        float del_eta_rec_gen_e=jteta1[jref]-jteta1gen[kref];
                        float del_phi_rec_gen_e =TMath::ACos(cos(jtphi1[jref]-jtphi1gen[kref]));
                        float R_rec_gen_e = sqrt(del_eta_rec_gen_e*del_eta_rec_gen_e + del_phi_rec_gen_e*del_phi_rec_gen_e);
                        if (R_rec_gen_e < 0.4){
                            for(int lref=0;lref<jtptgW.GetSize();lref++){
                                // if (jtptgW[lref]/sin(2*TMath::ATan(exp(-1*jtptgW[lref])))>20){
                                float del_eta_gen_e_w =jteta1gen[kref]-jtetagW[lref];
                                float del_phi_gen_e_w =TMath::ACos(cos(jtphi1gen[kref]-jtphigW[lref]));
                                float R_gen_e_w = sqrt(del_eta_gen_e_w*del_eta_gen_e_w + del_phi_gen_e_w*del_phi_gen_e_w);
                                if (R_gen_e_w < 0.4){ diff_R_gen_e_w = R_gen_e_w ;
                                    //   cout << counter <<" " << diff_R_rec_e_w-diff_R_gen_e_w << endl;
                                    if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>5 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<10)
                                    {del_R_gen_rec_E_W_5to10->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_5to10->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>10 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<15)
                                    {del_R_gen_rec_E_W_10to15->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_10to15->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>15 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<20)
                                    {del_R_gen_rec_E_W_15to20->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_15to20->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>20 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<25)
                                    {del_R_gen_rec_E_W_20to25->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_20to25->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>25 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<30)
                                    {del_R_gen_rec_E_W_25to30->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_25to30->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>30 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<35)
                                    {del_R_gen_rec_E_W_30to35->Fill(diff_R_rec_e_w-diff_R_gen_e_w); 
                                        del_R2_gen_rec_E_W_30to35->Fill(diff_R_gen_e_w,diff_R_rec_e_w); }
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>35 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<40)
                                    {del_R_gen_rec_E_W_35to40->Fill(diff_R_rec_e_w-diff_R_gen_e_w); 
                                        del_R2_gen_rec_E_W_35to40->Fill(diff_R_gen_e_w,diff_R_rec_e_w); }
                                    else  if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>40 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<45)
                                    {del_R_gen_rec_E_W_40to45->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_40to45->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>45 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<50)
                                    {del_R_gen_rec_E_W_45to50->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_45to50->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>50 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<55)
                                    {del_R_gen_rec_E_W_50to55->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_50to55->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    else if (jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))>55 && jtpt1[jref]/sin(2*TMath::ATan(exp(-1*jteta1[jref])))<60)
                                    {del_R_gen_rec_E_W_55to60->Fill(diff_R_rec_e_w-diff_R_gen_e_w);
                                        del_R2_gen_rec_E_W_55to60->Fill(diff_R_gen_e_w,diff_R_rec_e_w);}
                                    break;     }
                            }
                            break; }}}}
                                
                            
            
            
            for(int jref=0;jref<zgJtPt_Beta0p00ZCut0p101.GetSize();jref++){
                float diff_R_rec_w_g = 0; float diff_R_gen_w_g = 0;
                if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>5){
                    for(int iref=0;iref<jtptg.GetSize();iref++){
                        //     if (jtptg[iref]/sin(2*TMath::ATan(exp(-1*jtetag[iref])))>20){
                        float del_eta_rec_w_g =jtetag[iref]-zgJtEta_Beta0p00ZCut0p101[jref];
                        float del_phi_rec_w_g =TMath::ACos(cos(jtphig[iref]-zgJtPhi_Beta0p00ZCut0p101[jref]));
                        float R_rec_w_g = sqrt(del_eta_rec_w_g*del_eta_rec_w_g + del_phi_rec_w_g*del_phi_rec_w_g);
                        if (R_rec_w_g < 0.4){ diff_R_rec_w_g = R_rec_w_g ; break; }}
                    
                    for(int kref=0;kref<zgJtPt_Beta0p00ZCut0p101gen.GetSize();kref++){
                        // if (zgJtPt_Beta0p00ZCut0p101gen[kref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101gen[kref])))>20){
                        float del_eta_rec_gen_g=zgJtEta_Beta0p00ZCut0p101[jref]-zgJtEta_Beta0p00ZCut0p101gen[kref];
                        float del_phi_rec_gen_g =TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101[jref]-zgJtPhi_Beta0p00ZCut0p101gen[kref]));
                        float R_rec_gen_g = sqrt(del_eta_rec_gen_g*del_eta_rec_gen_g + del_phi_rec_gen_g*del_phi_rec_gen_g);
                        if (R_rec_gen_g < 0.4){
                            for(int lref=0;lref<jtptgW.GetSize();lref++){
                                //  if (jtptgW[lref]/sin(2*TMath::ATan(exp(-1*jtetagW[lref])))>20){
                                float del_eta_gen_w_g =jtetagW[lref]-zgJtEta_Beta0p00ZCut0p101gen[kref];
                                float del_phi_gen_w_g =TMath::ACos(cos(jtphigW[lref]-zgJtPhi_Beta0p00ZCut0p101gen[kref]));
                                float R_gen_w_g = sqrt(del_eta_gen_w_g*del_eta_gen_w_g + del_phi_gen_w_g*del_phi_gen_w_g);
                                if (R_gen_w_g < 0.4){diff_R_gen_w_g = R_gen_w_g ;
                                    if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>5 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<10))
                                    { del_R_gen_rec_W_g_5to10->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_5to10->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>10 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<15))
                                    { del_R_gen_rec_W_g_10to15->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_10to15->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>15 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<20))
                                    { del_R_gen_rec_W_g_15to20->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_15to20->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>20 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<25))
                                    { del_R_gen_rec_W_g_20to25->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_20to25->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>25 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<30))
                                    { del_R_gen_rec_W_g_25to30->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_25to30->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>30 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<35))
                                    { del_R_gen_rec_W_g_30to35->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_30to35->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>35 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<40))
                                    { del_R_gen_rec_W_g_35to40->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_35to40->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>40 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<45))
                                    { del_R_gen_rec_W_g_40to45->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_40to45->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>45 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<50))
                                    { del_R_gen_rec_W_g_45to50->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_45to50->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>50 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<55))
                                    { del_R_gen_rec_W_g_50to55->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_50to55->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    else if (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))>55 &&  (zgJtPt_Beta0p00ZCut0p101[jref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101[jref])))<60))
                                    { del_R_gen_rec_W_g_55to60->Fill(diff_R_rec_w_g-diff_R_gen_w_g);
                                        del_R2_gen_rec_W_g_55to60->Fill(diff_R_gen_w_g,diff_R_rec_w_g);}
                                    break;}
                            }
                            break;}}}}
                                        
      
            
        }    }
    
    cout << "NTupleAfterCut = " <<  NTupleAfterCut << " TotalChgEnergyMin = " << TotalChgEnergyMin << " NTrkMin = "  << NTrkMin << " STheta = " <<  STheta << " MissP = " << MissP << endl;
    
    
    TH1 *h1aa[6];
    TH1 *h1ba[6];
    TH1 *h1ca[6];
    TH1 *h2aa[6];
    TH1 *h2ba[6];
    TH1 *h2ca[6];
    TH1 *h3aa[6];
    TH1 *h3ba[6];
    TH1 *h3ca[6];
    TH1 *h4aa[6];
    TH1 *h5aa[6];
   
    TH2 *h9aa[6];
    TH2 *h10aa[6];
    TH2 *h11aa[6];
   
    
    TH1 *h6aa_5to10[6];  TH1 *h6aa_10to15[6];  TH1 *h6aa_15to20[6];  TH1 *h6aa_20to25[6];  TH1 *h6aa_25to30[6];  TH1 *h6aa_30to35[6];  TH1 *h6aa_35to40[6];  TH1 *h6aa_40to45[6];  TH1 *h6aa_45to50[6];  TH1 *h6aa_50to55[6]; TH1 *h6aa_55to60[6];
    TH1 *h7aa_5to10[6];  TH1 *h7aa_10to15[6];  TH1 *h7aa_15to20[6];  TH1 *h7aa_20to25[6];  TH1 *h7aa_25to30[6];  TH1 *h7aa_30to35[6];  TH1 *h7aa_35to40[6];  TH1 *h7aa_40to45[6];  TH1 *h7aa_45to50[6];  TH1 *h7aa_50to55[6]; TH1 *h7aa_55to60[6];
    TH1 *h8aa_5to10[6];  TH1 *h8aa_10to15[6];  TH1 *h8aa_15to20[6];  TH1 *h8aa_20to25[6];  TH1 *h8aa_25to30[6];  TH1 *h8aa_30to35[6];  TH1 *h8aa_35to40[6];  TH1 *h8aa_40to45[6];  TH1 *h8aa_45to50[6];  TH1 *h8aa_50to55[6]; TH1 *h8aa_55to60[6];
    
    TH1 *h12aa_5to10[6];  TH1 *h12aa_10to15[6];  TH1 *h12aa_15to20[6];  TH1 *h12aa_20to25[6];  TH1 *h12aa_25to30[6];  TH1 *h12aa_30to35[6];  TH1 *h12aa_35to40[6];  TH1 *h12aa_40to45[6];  TH1 *h12aa_45to50[6];  TH1 *h12aa_50to55[6]; TH1 *h12aa_55to60[6];
    TH1 *h13aa_5to10[6];  TH1 *h13aa_10to15[6];  TH1 *h13aa_15to20[6];  TH1 *h13aa_20to25[6];  TH1 *h13aa_25to30[6];  TH1 *h13aa_30to35[6];  TH1 *h13aa_35to40[6];  TH1 *h13aa_40to45[6];  TH1 *h13aa_45to50[6];  TH1 *h13aa_50to55[6]; TH1 *h13aa_55to60[6];
    TH1 *h14aa_5to10[6];  TH1 *h14aa_10to15[6];  TH1 *h14aa_15to20[6];  TH1 *h14aa_20to25[6];  TH1 *h14aa_25to30[6];  TH1 *h14aa_30to35[6];  TH1 *h14aa_35to40[6];  TH1 *h14aa_40to45[6];  TH1 *h14aa_45to50[6];  TH1 *h14aa_50to55[6]; TH1 *h14aa_55to60[6];
    
    TH1 *h15aa_5to10[6];  TH1 *h15aa_10to15[6];  TH1 *h15aa_15to20[6];  TH1 *h15aa_20to25[6];  TH1 *h15aa_25to30[6];  TH1 *h15aa_30to35[6];  TH1 *h15aa_35to40[6];  TH1 *h15aa_40to45[6];  TH1 *h15aa_45to50[6];  TH1 *h15aa_50to55[6]; TH1 *h15aa_55to60[6];
    TH1 *h16aa_5to10[6];  TH1 *h16aa_10to15[6];  TH1 *h16aa_15to20[6];  TH1 *h16aa_20to25[6];  TH1 *h16aa_25to30[6];  TH1 *h16aa_30to35[6];  TH1 *h16aa_35to40[6];  TH1 *h16aa_40to45[6];  TH1 *h16aa_45to50[6];  TH1 *h16aa_50to55[6]; TH1 *h16aa_55to60[6];
    TH1 *h17aa_5to10[6];  TH1 *h17aa_10to15[6];  TH1 *h17aa_15to20[6];  TH1 *h17aa_20to25[6];  TH1 *h17aa_25to30[6];  TH1 *h17aa_30to35[6];  TH1 *h17aa_35to40[6];  TH1 *h17aa_40to45[6];  TH1 *h17aa_45to50[6];  TH1 *h17aa_50to55[6]; TH1 *h17aa_55to60[6];
    
    
    for(int i=0;i<6;i++){
      h1aa[i] = new TH1F(Form("h1aa[%d]",i),"E scheme Jt pt",1000,0,60);
      h1ba[i] = new TH1F(Form("h1ba[%d]",i),"Wta Jt pt",1000,0,60);
      h1ca[i] = new TH1F(Form("h1ca[%d]",i),"groomed Jt pt",1000,0,60);

    h2aa[i] = new TH1F(Form("h2aa[%d]",i),"E scheme Jt Phi",100,-3.5,3.5);
    h2ba[i] = new TH1F(Form("h2ba[%d]",i),"WTA Jt phi",100,-3.5,3.5);
     h2ca[i] = new TH1F(Form("h2ca[%d]",i),"groomed Jt phi",100,-3.5,3.5);

     h3aa[i] = new TH1F(Form("h3aa[%d]",i),"E scheme Jt theta",100,0,3.3);
   h3ba[i] = new TH1F(Form("h3ba[%d]",i),"WTA Jt tehta",100,0,3.3);
   h3ca[i] = new TH1F(Form("h3ca[%d]",i),"groomed Jt theta",100,0,3.3);

   h4aa[i] = new TH1F(Form("h4aa[%d]",i),"E pt",100,-50,50);
   
    h5aa[i] = new TH1F(Form("h5aa[%d]",i),"E phi",100,-4,4);

   
        h6aa_5to10[i] = new TH1F(Form("h6aa_5to10[%d]",i),"rec, gen del_R_E_vs_g_5to10",100,-0.03,0.2);
       // h6aa_5to10[i]->GetYaxis()->SetTitle("Probability of R"); h6aa_5to10[i]->GetXaxis()->SetTitle("R");
            h6aa_10to15[i] = new TH1F(Form("h6aa_10to15[%d]",i),"rec, gen del_R_E_vs_g_10to15",100,-0.03,0.2);
      //  h6aa_10to15[i]->GetYaxis()->SetTitle("Probability of R"); h6aa_10to15[i]->GetXaxis()->SetTitle("R");
        h6aa_15to20[i] = new TH1F(Form("h6aa_15to20[%d]",i),"rec, gen del_R_E_vs_g_15to20",100,-0.03,0.2);
      //  h6aa_15to20[i]->GetYaxis()->SetTitle("Probability of R"); h6aa_15to20[i]->GetXaxis()->SetTitle("R");
        h6aa_20to25[i] = new TH1F(Form("h6aa_20to25[%d]",i),"rec, gen del_R_E_vs_g_20to25",100,-0.03,0.2);
      //  h6aa_20to25[i]->GetYaxis()->SetTitle("Probability of R");  h6aa_20to25[i]->GetXaxis()->SetTitle("R");
        h6aa_25to30[i] = new TH1F(Form("h6aa_25to30[%d]",i),"rec, gen del_R_E_vs_g_25to30",100,-0.03,0.2);
      //  h6aa_25to30[i]->GetYaxis()->SetTitle("Probability of R"); h6aa_25to30[i]->GetXaxis()->SetTitle("R");
       h6aa_30to35[i] = new TH1F(Form("h6aa_30to35[%d]",i),"rec, gen del_R_E_vs_g_30to35",100,-0.03,0.2);
     //   h6aa_30to35[i]->GetYaxis()->SetTitle("Probability of R"); h6aa_30to35[i]->GetXaxis()->SetTitle("R");
        h6aa_35to40[i] = new TH1F(Form("h6aa_35to40[%d]",i),"rec, gen del_R_E_vs_g_35to40",100,-0.03,0.2);
    //    h6aa_35to40[i]->GetYaxis()->SetTitle("Probability of R"); h6aa_35to40[i]->GetXaxis()->SetTitle("R");
        h6aa_40to45[i] = new TH1F(Form("h6aa_40to45[%d]",i),"rec, gen del_R_E_vs_g_40to45",100,-0.03,0.2);
   //     h6aa_40to45[i]->GetYaxis()->SetTitle("Probability of R"); h6aa_40to45[i]->GetXaxis()->SetTitle("R");
       h6aa_45to50[i] = new TH1F(Form("h6aa_45to50[%d]",i),"rec, gen del_R_E_vs_g_45to50",100,-0.03,0.2);
    //    h6aa_45to50[i]->GetYaxis()->SetTitle("Probability of R");h6aa_45to50[i]->GetXaxis()->SetTitle("R");
       h6aa_50to55[i] = new TH1F(Form("h6aa_50to55[%d]",i),"rec, gen del_R_E_vs_g_50to55",100,-0.03,0.2);
  //      h6aa_50to55[i]->GetYaxis()->SetTitle("Probability of R");  h6aa_50to55[i]->GetXaxis()->SetTitle("R");
    h6aa_55to60[i] = new TH1F(Form("h6aa_55to60[%d]",i),"rec, gen del_R_E_vs_g_55to60",100,-0.03,0.2);
  //      h6aa_55to60[i]->GetYaxis()->SetTitle("Probability of R");  h6aa_55to60[i]->GetXaxis()->SetTitle("R");
       
        
    
        h7aa_5to10[i] = new TH1F(Form("h7aa_5to10[%d]",i),"rec, gen del_R_E_vs_wta_5to10",100,-0.03,0.45);
   //     h7aa_5to10[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_5to10[i]->GetXaxis()->SetTitle("R");
        h7aa_10to15[i] = new TH1F(Form("h7aa_10to15[%d]",i),"rec, gen del_R_E_vs_wta_10to15",100,-0.03,0.45);
  //      h7aa_10to15[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_10to15[i]->GetXaxis()->SetTitle("R");
        h7aa_15to20[i] = new TH1F(Form("h7aa_15to20[%d]",i),"rec, gen del_R_E_vs_wta_15to20",100,-0.03,0.45);
   //     h7aa_15to20[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_15to20[i]->GetXaxis()->SetTitle("R");
        h7aa_20to25[i] = new TH1F(Form("h7aa_20to25[%d]",i),"rec, gen del_R_E_vs_wta_20to25",100,-0.03,0.45);
    //    h7aa_20to25[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_20to25[i]->GetXaxis()->SetTitle("R");
        h7aa_25to30[i] = new TH1F(Form("h7aa_25to30[%d]",i),"rec, gen del_R_E_vs_wta_25to30",100,-0.03,0.45);
  //      h7aa_25to30[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_25to30[i]->GetXaxis()->SetTitle("R");
        h7aa_30to35[i] = new TH1F(Form("h7aa_30to35[%d]",i),"rec, gen del_R_E_vs_wta_30to35",100,-0.03,0.45);
  //      h7aa_30to35[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_30to35[i]->GetXaxis()->SetTitle("R");
        h7aa_35to40[i] = new TH1F(Form("h7aa_35to40[%d]",i),"rec, gen del_R_E_vs_wta_35to40",100,-0.03,0.45);
  //      h7aa_35to40[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_35to40[i]->GetXaxis()->SetTitle("R");
        h7aa_40to45[i] = new TH1F(Form("h7aa_40to45[%d]",i),"rec, gen del_R_E_vs_wta_40to45",100,-0.03,0.45);
   //     h7aa_40to45[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_40to45[i]->GetXaxis()->SetTitle("R");
       h7aa_45to50[i] = new TH1F(Form("h7aa_45to50[%d]",i),"rec, gen del_R_E_vs_wta_45to50",100,-0.03,0.45);
   //     h7aa_45to50[i]->GetYaxis()->SetTitle("Probability of R"); h7aa_45to50[i]->GetXaxis()->SetTitle("R");
       h7aa_50to55[i] = new TH1F(Form("h7aa_50to55[%d]",i),"rec, gen del_R_E_vs_wta_50to55",100,-0.03,0.45);
 //       h7aa_50to55[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_50to55[i]->GetXaxis()->SetTitle("R");
       h7aa_55to60[i] = new TH1F(Form("h7aa_55to60[%d]",i),"rec, gen del_R_E_vs_wta_55to60",100,-0.03,0.45);
  //      h7aa_55to60[i]->GetYaxis()->SetTitle("Probability of R");  h7aa_55to60[i]->GetXaxis()->SetTitle("R");
        
      
        h8aa_5to10[i] = new TH1F(Form("h8aa_5to10[%d]",i),"rec, gen del_R_wta_vs_g_5to10",100,-0.03,0.45);
 //       h8aa_5to10[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_5to10[i]->GetXaxis()->SetTitle("R");
       h8aa_10to15[i] = new TH1F(Form("h8aa_10to15[%d]",i),"rec, gen del_R_wta_vs_g_10to15",100,-0.03,0.45);
 //       h8aa_10to15[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_10to15[i]->GetXaxis()->SetTitle("R");
        h8aa_15to20[i] = new TH1F(Form("h8aa_15to20[%d]",i),"rec, gen del_R_wta_vs_g_15to20",100,-0.03,0.45);
   //     h8aa_15to20[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_15to20[i]->GetXaxis()->SetTitle("R");
        h8aa_20to25[i] = new TH1F(Form("h8aa_20to25[%d]",i),"rec, gen del_R_wta_vs_g_20to25",100,-0.03,0.45);
     //   h8aa_20to25[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_20to25[i]->GetXaxis()->SetTitle("R");
        h8aa_25to30[i] = new TH1F(Form("h8aa_25to30[%d]",i),"rec, gen del_R_wta_vs_g_25to30",100,-0.03,0.45);
      //  h8aa_25to30[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_25to30[i]->GetXaxis()->SetTitle("R");
       h8aa_30to35[i] = new TH1F(Form("h8aa_30to35[%d]",i),"rec, gen del_R_wta_vs_g_30to35",100,-0.03,0.45);
      // h8aa_30to35[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_30to35[i]->GetXaxis()->SetTitle("R");
        h8aa_35to40[i] = new TH1F(Form("h8aa_35to40[%d]",i),"rec, gen del_R_wta_vs_g_35to40",100,-0.03,0.45);
      //  h8aa_35to40[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_35to40[i]->GetXaxis()->SetTitle("R");
        h8aa_40to45[i] = new TH1F(Form("h8aa_40to45[%d]",i),"rec, gen del_R_wta_vs_g_40to45",100,-0.03,0.45);
       // h8aa_40to45[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_40to45[i]->GetXaxis()->SetTitle("R");
       h8aa_45to50[i] = new TH1F(Form("h8aa_45to50[%d]",i),"rec, gen del_R_wta_vs_g_45to50",100,-0.03,0.45);
     // h8aa_45to50[i]->GetYaxis()->SetTitle("Probability of R");   h8aa_45to50[i]->GetXaxis()->SetTitle("R");
       h8aa_50to55[i] = new TH1F(Form("h8aa_50to55[%d]",i),"rec, gen del_R_wta_vs_g_50to55",100,-0.03,0.45);
  //     h8aa_50to55[i]->GetYaxis()->SetTitle("Probability of R"); h8aa_50to55[i]->GetXaxis()->SetTitle("R");
        h8aa_55to60[i] = new TH1F(Form("h8aa_55to60[%d]",i),"rec, gen del_R_wta_vs_g_55to60",100,-0.03,0.45);
  //      h8aa_55to60[i]->GetYaxis()->SetTitle("Probability of R");  h8aa_55to60[i]->GetXaxis()->SetTitle("R");
       

      h9aa[i] = new TH2F(Form("h9aa[%d]",i), "del phi vs del eta of E,g",100,-0.2,0.2,100,-0.2,0.2);
      h9aa[i]->GetXaxis()->SetTitle("del eta");h9aa[i]->GetXaxis()->CenterTitle();
    h9aa[i]->GetYaxis()->SetTitle("del phi");h9aa[i]->GetYaxis()->CenterTitle();
    
       h10aa[i] = new TH2F(Form("h10aa[%d]",i), "del phi vs del eta of E,wta",100,-0.2,0.2,100,-0.2,0.2);
       h10aa[i]->GetXaxis()->SetTitle("del eta");h10aa[i]->GetXaxis()->CenterTitle();
    h10aa[i]->GetYaxis()->SetTitle("del phi");h10aa[i]->GetYaxis()->CenterTitle();
    
        h11aa[i] = new TH2F(Form("h11[%d]",i), "del phi vs del eta of wta,g",100,-0.2,0.2,100,-0.2,0.2);
     h11aa[i]->GetXaxis()->SetTitle("del eta");h11aa[i]->GetXaxis()->CenterTitle();
    h11aa[i]->GetYaxis()->SetTitle("del phi");h11aa[i]->GetYaxis()->CenterTitle();

   
        h12aa_5to10[i] = new TH1F(Form("h12aa_5to10[%d]",i),"rec gen del eta E g 5 to 10",100,-0.2,0.2);
        h12aa_10to15[i] = new TH1F(Form("h12aa_10to15[%d]",i),"rec gen del eta E g 10 to 15",100,-0.2,0.2);
        h12aa_15to20[i] = new TH1F(Form("h12aa_15to20[%d]",i),"rec gen del eta E g 15 to 20",100,-0.2,0.2);
        h12aa_20to25[i] = new TH1F(Form("h12aa_20to25[%d]",i),"rec gen del eta E g 20 to 25",100,-0.2,0.2);
        h12aa_25to30[i] = new TH1F(Form("h12aa_25to30[%d]",i),"rec gen del eta E g 25 to 30",100,-0.2,0.2);
        h12aa_30to35[i] = new TH1F(Form("h12aa_30to35[%d]",i),"rec gen del eta E g 30 to 35",100,-0.2,0.2);
        h12aa_35to40[i] = new TH1F(Form("h12aa_35to40[%d]",i),"rec gen del eta E g 35 to 40",100,-0.2,0.2);
        h12aa_40to45[i] = new TH1F(Form("h12aa_40to45[%d]",i),"rec gen del eta E g 40 to 45",100,-0.2,0.2);
        h12aa_45to50[i] = new TH1F(Form("h12aa_45to50[%d]",i),"rec gen del eta E g 45 to 50",100,-0.2,0.2);
        h12aa_50to55[i] = new TH1F(Form("h12aa_50to55[%d]",i),"rec gen del eta E g 50 to 55",100,-0.2,0.2);
        h12aa_55to60[i] = new TH1F(Form("h12aa_55to60[%d]",i),"rec gen del eta E g 55 to 60",100,-0.2,0.2);

        
        
   
        h13aa_5to10[i] = new TH1F(Form("h13aa_5to10[%d]",i),"rec gen del phi E g_5 to 10",100,-0.2,0.2);
        h13aa_10to15[i] = new TH1F(Form("h13aa_10to15[%d]",i),"rec gen del phi E g_10 to 15",100,-0.2,0.2);
        h13aa_15to20[i] = new TH1F(Form("h13aa_15to20[%d]",i),"rec gen del phi E g_15 to 20",100,-0.2,0.2);
        h13aa_20to25[i] = new TH1F(Form("h13aa_20to25[%d]",i),"rec gen del phi E g_20 to 25",100,-0.2,0.2);
        h13aa_25to30[i] = new TH1F(Form("h13aa_25to30[%d]",i),"rec gen del phi E g_25 to 30",100,-0.2,0.2);
        h13aa_30to35[i] = new TH1F(Form("h13aa_30to35[%d]",i),"rec gen del phi E g_30 to 35",100,-0.2,0.2);
        h13aa_35to40[i] = new TH1F(Form("h13aa_35to40[%d]",i),"rec gen del phi E g_35 to 40",100,-0.2,0.2);
        h13aa_40to45[i] = new TH1F(Form("h13aa_40to45[%d]",i),"rec gen del phi E g_40 to 45",100,-0.2,0.2);
        h13aa_45to50[i] = new TH1F(Form("h13aa_45to50[%d]",i),"rec gen del phi E g_45 to 50",100,-0.2,0.2);
        h13aa_50to55[i] = new TH1F(Form("h13aa_50to55[%d]",i),"rec gen del phi E g_50 to 55",100,-0.2,0.2);
        h13aa_55to60[i] = new TH1F(Form("h13aa_55to60[%d]",i),"rec gen del phi E g_55 to 60",100,-0.2,0.2);
        
  
        h14aa_5to10[i] = new TH1F(Form("h14aa_5to10[%d]",i),"rec gen del eta E wta_5 to 10",100,-0.4,0.4);
        h14aa_10to15[i] = new TH1F(Form("h14aa_10to15[%d]",i),"rec gen del eta E wta_10 to 15",100,-0.4,0.4);
        h14aa_15to20[i] = new TH1F(Form("h14aa_15to20[%d]",i),"rec gen del eta E wta_15 to 20",100,-0.4,0.4);
        h14aa_20to25[i] = new TH1F(Form("h14aa_20to25[%d]",i),"rec gen del eta E wta_20 to 25",100,-0.4,0.4);
        h14aa_25to30[i] = new TH1F(Form("h14aa_25to30[%d]",i),"rec gen del eta E wta_25 to 30",100,-0.4,0.4);
        h14aa_30to35[i] = new TH1F(Form("h14aa_30to35[%d]",i),"rec gen del eta E wta_30 to 35",100,-0.4,0.4);
        h14aa_35to40[i] = new TH1F(Form("h14aa_35to40[%d]",i),"rec gen del eta E wta_35 to 40",100,-0.4,0.4);
        h14aa_40to45[i] = new TH1F(Form("h14aa_40to45[%d]",i),"rec gen del eta E wta_40 to 45",100,-0.4,0.4);
        h14aa_45to50[i] = new TH1F(Form("h14aa_45to50[%d]",i),"rec gen del eta E wta_45 to 50",100,-0.4,0.4);
        h14aa_50to55[i] = new TH1F(Form("h14aa_50to55[%d]",i),"rec gen del eta E wta_50 to 55",100,-0.4,0.4);
        h14aa_55to60[i] = new TH1F(Form("h14aa_55to60[%d]",i),"rec gen del eta E wta_55 to 60",100,-0.4,0.4);
        
        
        h15aa_5to10[i] = new TH1F(Form("h15aa_5to10[%d]",i),"rec gen del phi E wta_5 to 10",100,-.4,.4);
        h15aa_10to15[i] = new TH1F(Form("h15aa_10to15[%d]",i),"rec gen del phi E wta_10 to 15",100,-.4,.4);
        h15aa_15to20[i] = new TH1F(Form("h15aa_15to20[%d]",i),"rec gen del phi E wta_15 to 20",100,-.4,.4);
        h15aa_20to25[i] = new TH1F(Form("h15aa_20to25[%d]",i),"rec gen del phi E wta_20 to 25",100,-.4,.4);
        h15aa_25to30[i] = new TH1F(Form("h15aa_25to30[%d]",i),"rec gen del phi E wta_25 to 30",100,-.4,.4);
        h15aa_30to35[i] = new TH1F(Form("h15aa_30to35[%d]",i),"rec gen del phi E wta_30 to 35",100,-.4,.4);
        h15aa_35to40[i] = new TH1F(Form("h15aa_35to40[%d]",i),"rec gen del phi E wta_35 to 40",100,-.4,.4);
        h15aa_40to45[i] = new TH1F(Form("h15aa_40to45[%d]",i),"rec gen del phi E wta_40 to 45",100,-.4,.4);
        h15aa_45to50[i] = new TH1F(Form("h15aa_45to50[%d]",i),"rec gen del phi E wta_45 to 50",100,-.4,.4);
        h15aa_50to55[i] = new TH1F(Form("h15aa_50to55[%d]",i),"rec gen del phi E wta_50 to 55",100,-.4,.4);
        h15aa_55to60[i] = new TH1F(Form("h15aa_55to60[%d]",i),"rec gen del phi E wta_55 to 60",100,-.4,.4);
        
  //  h16aa[i] = new TH1F(Form("h16aa[%d]",i),"del eta g wta",100,-0.4,0.4);
   
        
        h16aa_5to10[i] = new TH1F(Form("h16aa_5to10[%d]",i),"rec gen del eta g wta_5 to 10",100,-0.4,0.4);
        h16aa_10to15[i] = new TH1F(Form("h16aa_10to15[%d]",i),"rec gen del eta g wta_10 to 15",100,-0.4,0.4);
        h16aa_15to20[i] = new TH1F(Form("h16aa_15to20[%d]",i),"rec gen del eta g wta_15 to 20",100,-0.4,0.4);
        h16aa_20to25[i] = new TH1F(Form("h16aa_20to25[%d]",i),"rec gen del eta g wta_20 to 25",100,-0.4,0.4);
        h16aa_25to30[i] = new TH1F(Form("h16aa_25to30[%d]",i),"rec gen del eta g wta_25 to 30",100,-0.4,0.4);
        h16aa_30to35[i] = new TH1F(Form("h16aa_30to35[%d]",i),"rec gen del eta g wta_30 to 35",100,-0.4,0.4);
        h16aa_35to40[i] = new TH1F(Form("h16aa_35to40[%d]",i),"rec gen del eta g wta_35 to 40",100,-0.4,0.4);
        h16aa_40to45[i] = new TH1F(Form("h16aa_40to45[%d]",i),"rec gen del eta g wta_40 to 45",100,-0.4,0.4);
        h16aa_45to50[i] = new TH1F(Form("h16aa_45to50[%d]",i),"rec gen del eta g wta_45 to 50",100,-0.4,0.4);
        h16aa_50to55[i] = new TH1F(Form("h16aa_50to55[%d]",i),"rec gen del eta g wta_50 to 55",100,-0.4,0.4);
        h16aa_55to60[i] = new TH1F(Form("h16aa_55to60[%d]",i),"rec gen del eta g wta_55 to 60",100,-0.4,0.4);
        
    //  h17aa[i] = new TH1F(Form("h17aa[%d]",i),"del phi g wta",100,-0.4,0.4);
    
        
        h17aa_5to10[i] = new TH1F(Form("h17aa_5to10[%d]",i),"rec gen del phi g wta_5 to 10",100,-.4,.4);
        h17aa_10to15[i] = new TH1F(Form("h17aa_10to15[%d]",i),"rec gen del phi g wta_10 to 15",100,-.4,.4);
        h17aa_15to20[i] = new TH1F(Form("h17aa_15to20[%d]",i),"rec gen del phi g wta_15 to 20",100,-.4,.4);
        h17aa_20to25[i] = new TH1F(Form("h17aa_20to25[%d]",i),"rec gen del phi g wta_20 to 25",100,-.4,.4);
        h17aa_25to30[i] = new TH1F(Form("h17aa_25to30[%d]",i),"rec gen del phi g wta_25 to 30",100,-.4,.4);
        h17aa_30to35[i] = new TH1F(Form("h17aa_30to35[%d]",i),"rec gen del phi g wta_30 to 35",100,-.4,.4);
        h17aa_35to40[i] = new TH1F(Form("h17aa_35to40[%d]",i),"rec gen del phi g wta_35 to 40",100,-.4,.4);
        h17aa_40to45[i] = new TH1F(Form("h17aa_40to45[%d]",i),"rec gen del phi g wta_40 to 45",100,-.4,.4);
        h17aa_45to50[i] = new TH1F(Form("h17aa_45to50[%d]",i),"rec gen del phi g wta_45 to 50",100,-.4,.4);
        h17aa_50to55[i] = new TH1F(Form("h17aa_50to55[%d]",i),"rec gen del phi g wta_50 to 55",100,-.4,.4);
        h17aa_55to60[i] = new TH1F(Form("h17aa_55to60[%d]",i),"rec gen del phi g wta_55 to 60",100,-.4,.4);

    }


    for(int ifile=0;ifile<6;ifile++){
      TFile *fa;
    if(ifile==0) fa = new TFile("LEP1Data1992_recons_aftercut-MERGED.root");
    else if(ifile==1) fa = new TFile("LEP1Data1993_recons_aftercut-MERGED.root");
    else if(ifile==2) fa = new TFile("LEP1Data1994P1_recons_aftercut-MERGED.root");
    else if(ifile==3) fa = new TFile("LEP1Data1994P2_recons_aftercut-MERGED.root");
    else if(ifile==4) fa = new TFile("LEP1Data1994P3_recons_aftercut-MERGED.root");
     else if(ifile==5) fa = new TFile("LEP1Data1995_recons_aftercut-MERGED.root");

      
    TTree *treea = (TTree*) fa->Get("akR4ESchemeJetTree");
    TTree *tree_ga = (TTree*) fa->Get("akR4WTAmodpSchemeJetTree");
    
    cout<<"Analyzing "<<tree->GetEntries()<<" events!"<<endl;

    //Create Array Reader
    TTreeReader tra(treea);
    TTreeReader tr_ga(tree_ga);
    
    TTreeReaderArray<int>   nref1a(tra, "nref");
        TTreeReaderArray<float> jtpt1a(tra, "jtpt");
     TTreeReaderArray<float> jteta1a(tra, "jteta");
      TTreeReaderArray<float> jtphi1a(tra, "jtphi");
       TTreeReaderArray<float> jtm1a(tra, "jtm");
        TTreeReaderArray<int> jtN1a(tra, "jtN");
         TTreeReaderArray<int> jtNPW1a(tra, "jtNPW");
          TTreeReaderArray<float> jtptFracPW1a(tra, "jtptFracPW");
           TTreeReaderArray<float> zgJtPt_Beta0p00ZCut0p101a(tra, "zgJtPt_Beta0p00ZCut0p10");
            TTreeReaderArray<float> zgJtPhi_Beta0p00ZCut0p101a(tra, "zgJtPhi_Beta0p00ZCut0p10");
         TTreeReaderArray<float> zgJtEta_Beta0p00ZCut0p101a(tra, "zgJtEta_Beta0p00ZCut0p10");
         TTreeReaderArray<float> zg_Beta0p00ZCut0p101a(tra, "zg_Beta0p00ZCut0p10");
          TTreeReaderArray<float> rg_Beta0p00ZCut0p101a(tra, "rg_Beta0p00ZCut0p10");
       

TTreeReaderArray<int>   nrefga(tr_ga, "nref");
        TTreeReaderArray<float> jtptga(tr_ga, "jtpt");
         TTreeReaderArray<float> jtetaga(tr_ga, "jteta");
          TTreeReaderArray<float> jtphiga(tr_ga, "jtphi");
           TTreeReaderArray<float> jtmga(tr_ga, "jtm");
            TTreeReaderArray<int> jtNga(tr_ga, "jtN");
             TTreeReaderArray<int> jtNPWga(tr_ga, "jtNPW");
              TTreeReaderArray<float> jtptFracPWga(tr_ga, "jtptFracPW");
               TTreeReaderArray<float> zgJtPt_Beta0p00ZCut0p10ga(tr_ga, "zgJtPt_Beta0p00ZCut0p10");
                TTreeReaderArray<float> zgJtPhi_Beta0p00ZCut0p10ga(tr_ga, "zgJtPhi_Beta0p00ZCut0p10");
                 TTreeReaderArray<float> zgJtEta_Beta0p00ZCut0p10ga(tr_ga, "zgJtEta_Beta0p00ZCut0p10");
                 TTreeReaderArray<float> zg_Beta0p00ZCut0p10ga(tr_ga, "zg_Beta0p00ZCut0p10");
                  TTreeReaderArray<float> rg_Beta0p00ZCut0p10ga(tr_ga, "rg_Beta0p00ZCut0p10");
          
    int countera(0);

    //Loop over events
    while (tra.Next() && tr_ga.Next()) {

        if(countera%100==0) cout<<"Analyzing event "<<countera<<endl;
        countera++;

        //Loop over generated particles
        for(int iref=0;iref<jtpt1a.GetSize();iref++){
          if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>20.0){

        h1aa[ifile]->Fill(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref]))));
       h1ca[ifile]->Fill(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref]))));
        h2aa[ifile]->Fill(jtphi1a[iref]);
        h2ca[ifile]->Fill(zgJtPhi_Beta0p00ZCut0p101a[iref]);
        h3aa[ifile]->Fill(2*TMath::ATan(exp(-1*jteta1a[iref])));
        h3ca[ifile]->Fill(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])));
        //    h4[ifile]->Fill(jtpt1);
        //    h5[ifile]->Fill(jtphi1);
                    

            float del_eta_E_vs_g = jteta1a[iref] - zgJtEta_Beta0p00ZCut0p101a[iref];
       //   h12aa[ifile]->Fill(del_eta_E_vs_g);
              float del_phi_E_vs_g = TMath::ACos(cos(jtphi1a[iref] - zgJtPhi_Beta0p00ZCut0p101a[iref]));
     //   h13aa[ifile]->Fill(del_phi_E_vs_g);
        float del_R_E_vs_g = sqrt(del_eta_E_vs_g*del_eta_E_vs_g + del_phi_E_vs_g*del_phi_E_vs_g);
     //     h6aa[ifile]->Fill(del_R_E_vs_g);
          h9aa[ifile]->Fill(del_eta_E_vs_g,del_phi_E_vs_g);
          }}
        
        for(int iref=0;iref<jtpt1a.GetSize();iref++){ //jtpt1.GetSize()
            if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>5){
                float del_eta_E_vs_g = jteta1a[iref] - zgJtEta_Beta0p00ZCut0p101a[iref];
                float del_phi_E_vs_g = TMath::ACos(cos(jtphi1a[iref] - zgJtPhi_Beta0p00ZCut0p101a[iref]));
                float del_R_E_vs_g = sqrt(del_eta_E_vs_g*del_eta_E_vs_g + del_phi_E_vs_g*del_phi_E_vs_g);
                if(del_R_E_vs_g<0.4){
                    if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>5 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<10){
                        h6aa_5to10[ifile]->Fill(del_R_E_vs_g);
                        h12aa_5to10[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_5to10[ifile]->Fill(del_phi_E_vs_g);}
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>10 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<15){
                        h12aa_10to15[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_10to15[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_10to15[ifile]->Fill(del_R_E_vs_g);}
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>15 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<20){
                        h12aa_15to20[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_15to20[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_15to20[ifile]->Fill(del_R_E_vs_g);}
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>20 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<25){
                        h12aa_20to25[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_20to25[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_20to25[ifile]->Fill(del_R_E_vs_g);}
                    
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>25 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<30){
                        h12aa_25to30[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_25to30[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_25to30[ifile]->Fill(del_R_E_vs_g);}
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>30 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<35){
                        h12aa_30to35[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_30to35[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_30to35[ifile]->Fill(del_R_E_vs_g);}
                    
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>35 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<40){
                        h12aa_35to40[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_35to40[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_35to40[ifile]->Fill(del_R_E_vs_g);}
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>40 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<45){
                        h12aa_40to45[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_40to45[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_40to45[ifile]->Fill(del_R_E_vs_g);}
                    
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>45 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<50){
                        h12aa_45to50[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_45to50[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_45to50[ifile]->Fill(del_R_E_vs_g);}
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>50 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<55){
                        h12aa_50to55[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_50to55[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_50to55[ifile]->Fill(del_R_E_vs_g);}
                    else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>55 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<60){
                        h12aa_55to60[ifile]->Fill(del_eta_E_vs_g);
                        h13aa_55to60[ifile]->Fill(del_phi_E_vs_g);
                        h6aa_55to60[ifile]->Fill(del_R_E_vs_g);}
                    
                }}}
  
        
          for(int jref=0;jref<jtptga.GetSize();jref++){
        if (jtptga[jref]/sin(2*TMath::ATan(exp(-1*jtetaga[jref])))>20.0){
          h1ba[ifile]->Fill(jtptga[jref]/sin(2*TMath::ATan(exp(-1*jtetaga[jref]))));
          h2ba[ifile]->Fill(jtphiga[jref]);
          h3ba[ifile]->Fill(2*TMath::ATan(exp(-1*jtetaga[jref])));
        }}

         
          
            for(int iref=0;iref<jtpt1a.GetSize();iref++){
                if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>5){
                    for(int jref=0;jref<jtptga.GetSize();jref++){
                        float del_eta_E_vs_wta = jteta1a[iref] - jtetaga[jref];
                        float  del_phi_E_vs_wta = TMath::ACos(cos(jtphi1a[iref] - jtphiga[jref]));
                        float del_R_E_vs_wta = sqrt(del_eta_E_vs_wta*del_eta_E_vs_wta +  del_phi_E_vs_wta * del_phi_E_vs_wta);
                        if (del_R_E_vs_wta < 0.4){
                            if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>5 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<10){
                                h14aa_5to10[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_5to10[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_5to10[ifile]->Fill(del_R_E_vs_wta);}
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>10 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<15){
                                h14aa_10to15[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_10to15[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_10to15[ifile]->Fill(del_R_E_vs_wta);}
                            
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>15 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<20){
                                h14aa_15to20[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_15to20[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_15to20[ifile]->Fill(del_R_E_vs_wta);}
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>20 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<25){
                                h14aa_20to25[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_20to25[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_20to25[ifile]->Fill(del_R_E_vs_wta);}
                            
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>25 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<30){
                                h14aa_25to30[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_25to30[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_25to30[ifile]->Fill(del_R_E_vs_wta);}
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>30 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<35){
                                h14aa_30to35[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_30to35[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_30to35[ifile]->Fill(del_R_E_vs_wta);}
                            
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>35 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<40){
                                h14aa_35to40[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_35to40[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_35to40[ifile]->Fill(del_R_E_vs_wta);}
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>40 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<45){
                                h14aa_40to45[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_40to45[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_40to45[ifile]->Fill(del_R_E_vs_wta);}
                            
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>45 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<50){
                                h14aa_45to50[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_45to50[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_45to50[ifile]->Fill(del_R_E_vs_wta);}
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>50 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<55){
                                h14aa_50to55[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_50to55[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_50to55[ifile]->Fill(del_R_E_vs_wta);}
                            else if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>55 && jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))<60){
                                h14aa_55to60[ifile]->Fill(del_eta_E_vs_wta);
                                h15aa_55to60[ifile]->Fill(del_phi_E_vs_wta);
                                h7aa_55to60[ifile]->Fill(del_R_E_vs_wta);}
                            break;
                            
                        }}}}
        
        for(int iref=0;iref<zgJtPt_Beta0p00ZCut0p101.GetSize();iref++){
            if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>5){
                for(int jref=0;jref<jtptga.GetSize();jref++){
                    //      if (jtptg[jref]/sin(2*TMath::ATan(exp(-1*jtetag[jref])))>20){
                    auto del_eta_g_vs_wta = zgJtEta_Beta0p00ZCut0p101a[iref] - jtetaga[jref];
                    auto del_phi_g_vs_wta = TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101a[iref] -  jtphiga[jref]));
                    auto del_R_g_vs_wta = sqrt(del_eta_g_vs_wta*del_eta_g_vs_wta + del_phi_g_vs_wta*del_phi_g_vs_wta);
                    if(del_R_g_vs_wta <0.4){
                        if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>5 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<10)){
                            h16aa_5to10[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_5to10[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_5to10[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>10 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<15)){
                            h16aa_10to15[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_10to15[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_10to15[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>15 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<20)){
                            h16aa_15to20[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_15to20[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_15to20[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>20 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<25)){
                            h16aa_20to25[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_20to25[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_20to25[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>25 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<30)){
                            h16aa_25to30[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_25to30[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_25to30[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>30 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<35)){
                            h16aa_30to35[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_30to35[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_30to35[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>35 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<40)){
                            h16aa_35to40[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_35to40[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_35to40[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>40 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<45)){
                            h16aa_40to45[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_40to45[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_40to45[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>45 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<50)){
                            h16aa_45to50[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_45to50[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_45to50[ifile]->Fill(del_R_g_vs_wta);}
                        
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>50 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<55)){
                            h16aa_50to55[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_50to55[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_50to55[ifile]->Fill(del_R_g_vs_wta);}
                        else if(zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))>55 &&  (zgJtPt_Beta0p00ZCut0p101a[iref]/sin(2*TMath::ATan(exp(-1*zgJtEta_Beta0p00ZCut0p101a[iref])))<60)){
                            h16aa_55to60[ifile]->Fill(del_eta_g_vs_wta);
                            h17aa_55to60[ifile]->Fill(del_phi_g_vs_wta);
                            h8aa_55to60[ifile]->Fill(del_R_g_vs_wta);}
                        break;  }
                    
                }}}
        
        for(int iref=0;iref<jtpt1a.GetSize();iref++){
            if(jtpt1a[iref]/sin(2*TMath::ATan(exp(-1*jteta1a[iref])))>20.0){
      for(int jref=0;jref<jtptga.GetSize();jref++){
          float del_eta_E_vs_wta = jteta1a[iref] - jtetaga[jref];
          float  del_phi_E_vs_wta = TMath::ACos(cos(jtphi1a[iref] - jtphiga[jref]));
        float del_R_E_vs_wta = sqrt(del_eta_E_vs_wta*del_eta_E_vs_wta +  del_phi_E_vs_wta * del_phi_E_vs_wta);
        if (del_R_E_vs_wta < 0.4)
        {
    //      h7aa[ifile]->Fill(del_R_E_vs_wta);
  //      h15aa[ifile]->Fill(del_phi_E_vs_wta);
  //      h14aa[ifile]->Fill(del_eta_E_vs_wta);
        h10aa[ifile]->Fill(del_eta_E_vs_wta, del_phi_E_vs_wta);
        }
        auto del_eta_g_vs_wta = zgJtEta_Beta0p00ZCut0p101a[iref] - jtetaga[jref];
            auto del_phi_g_vs_wta = TMath::ACos(cos(zgJtPhi_Beta0p00ZCut0p101a[iref] -  jtphiga[jref]));
        auto del_R_g_vs_wta = sqrt(del_eta_g_vs_wta*del_eta_g_vs_wta + del_phi_g_vs_wta*del_phi_g_vs_wta);
        if(del_R_g_vs_wta <0.4)
          {
        //h8aa[ifile]->Fill(del_R_g_vs_wta);
           //   h16aa[ifile]->Fill(del_eta_g_vs_wta);
          //    h17aa[ifile]->Fill(del_phi_g_vs_wta);
          }          h11aa[ifile]->Fill(del_eta_g_vs_wta,del_phi_g_vs_wta);
        }}

    }
    }
    }
    //Make plots
    
    
    
    
    
   
    

        h1aa[0]->Add(h1aa[1]); h1aa[0]->Add(h1aa[2]);h1aa[0]->Add(h1aa[3]);h1aa[0]->Add(h1aa[4]);h1aa[0]->Add(h1aa[5]);
    h1ba[0]->Add(h1ba[1]); h1ba[0]->Add(h1ba[2]);h1ba[0]->Add(h1ba[3]);h1ba[0]->Add(h1ba[4]);h1ba[0]->Add(h1ba[5]);
    h1ca[0]->Add(h1ca[1]); h1ca[0]->Add(h1ca[2]);h1ca[0]->Add(h1ca[3]);h1ca[0]->Add(h1ca[4]);h1ca[0]->Add(h1ca[5]);
    
    h2aa[0]->Add(h2aa[1]); h2aa[0]->Add(h2aa[2]);  h2aa[0]->Add(h2aa[3]); h2aa[0]->Add(h2aa[4]); h2aa[0]->Add(h2aa[5]);
    h2ba[0]->Add(h2ba[1]); h2ba[0]->Add(h2ba[2]);  h2ba[0]->Add(h2ba[3]); h2ba[0]->Add(h2ba[4]); h2ba[0]->Add(h2ba[5]);
    h2ca[0]->Add(h2ca[1]); h2ca[0]->Add(h2ca[2]);  h2ca[0]->Add(h2ca[3]); h2ca[0]->Add(h2ca[4]); h2ca[0]->Add(h2ca[5]);
   
    h3aa[0]->Add(h3aa[1]); h3aa[0]->Add(h3aa[2]);  h3aa[0]->Add(h3aa[3]); h3aa[0]->Add(h3aa[4]); h3aa[0]->Add(h3aa[5]);
    h3ba[0]->Add(h3ba[1]); h3ba[0]->Add(h3ba[2]);  h3ba[0]->Add(h3ba[3]); h3ba[0]->Add(h3ba[4]); h3ba[0]->Add(h3ba[5]);
    h3ca[0]->Add(h3ca[1]); h3ca[0]->Add(h3ca[2]);  h3ca[0]->Add(h3ca[3]); h3ca[0]->Add(h3ca[4]); h3ca[0]->Add(h3ca[5]);
    
    
    h1aa[0]->SetLineColor(kGreen);
    h1ba[0]->SetLineColor(kGreen);
    h1ca[0]->SetLineColor(kGreen);
    h2aa[0]->SetLineColor(kGreen);
    h2ba[0]->SetLineColor(kGreen);
    h2ca[0]->SetLineColor(kGreen);
    h3aa[0]->SetLineColor(kGreen);
    h3ba[0]->SetLineColor(kGreen);
    h3ca[0]->SetLineColor(kGreen);
    
    
    
    cout << "NTupleAfterCut = " << NTupleAfterCut << " TotalChgEnergyMin = " << TotalChgEnergyMin << " NTrkMin = " << NTrkMin << " STheta = " << STheta << " MissP = " << MissP << endl;
    cout << " counter2 = " << counter2 << " counter3 = " << counter3 << " counter4 = " << counter4 << " counter5 = " << counter5 << " counter6 = " << counter6 << " counter7 = " << counter7 << " counter8 = " << counter8 << " counter10 = " << counter10 << " counter11 = " << counter11 << " counter12 = " << counter12 << " counter13 = " << counter13 <<   endl;
    
    
    
    
    cout << "rec p 5 to 10 = " << counter1 << endl;
    cout << "rec p 10 to 10 = " << counter2 << endl;
    cout << "rec p 15 to 10 = " << counter3 << endl;
    cout << "rec p 20 to 10 = " << counter4 << endl;
    cout << "rec p 25 to 10 = " << counter5 << endl;
    cout << "rec p 30 to 10 = " << counter6 << endl;
    cout << "rec p 35 to 10 = " << counter7 << endl;
    cout << "rec p 40 to 10 = " << counter8 << endl;
    cout << "rec p 45 to 10 = " << counter9 << endl;
    cout << "rec p 50 to 10 = " << counter10 << endl;
    cout << "rec p 55 to 10 = " << counter11 << endl;
    
    cout << "gen p 5 to 10 = " << counter21 << endl;
    cout << "gen p 10 to 10 = " << counter22 << endl;
    cout << "gen p 15 to 10 = " << counter23 << endl;
    cout << "gen p 20 to 10 = " << counter24 << endl;
    cout << "gen p 25 to 10 = " << counter25 << endl;
    cout << "gen p 30 to 10 = " << counter26 << endl;
    cout << "gen p 35 to 10 = " << counter27 << endl;
    cout << "gen p 40 to 10 = " << counter28 << endl;
    cout << "gen p 45 to 10 = " << counter29 << endl;
    cout << "gen p 50 to 10 = " << counter30 << endl;
    cout << "gen p 55 to 10 = " << counter31 << endl;

    //Make plots

    Double_t factor = 1.;
    
    h1a->Scale(factor/h1a->GetEntries());
    cout << "h1a = " << h1a->GetEntries()<<endl;
    h1b->Scale(factor/h1b->GetEntries());
    cout << "h1b = " << h1b->GetEntries()<<endl;
    h1c->Scale(factor/h1c->GetEntries());
    cout << "h1c = " << h1c->GetEntries()<<endl;
    h1d->Scale(factor/h1d->GetEntries());
    cout << "h1d = " << h1d->GetEntries()<<endl;
    h1e->Scale(factor/h1e->GetEntries());
    cout << "h1e = " << h1e->GetEntries()<<endl;
   h1f->Scale(factor/h1f->GetEntries());
    cout << "h1f = " << h1f->GetEntries()<<endl;
    
//    cout << "h1a entries = " << h1a->GetEntries() << "h1d entries = " << h1d->GetEntries() << endl;
    cout << "h2a = " << h2a->GetEntries()<<endl;
    h2a->Scale(factor/h2a->GetEntries());
    cout << "h2b = " << h2b->GetEntries()<<endl;
    h2b->Scale(factor/h2b->GetEntries());
    cout << "h2c = " << h2c->GetEntries()<<endl;
   h2c->Scale(factor/h2c->GetEntries());
    cout << "h2d = " << h2d->GetEntries()<<endl;
    h2d->Scale(factor/h2d->GetEntries());
    cout << "h2e = " << h2e->GetEntries()<<endl;
   h2e->Scale(factor/h2e->GetEntries());
    cout << "h2f = " << h2f->GetEntries()<<endl;
    h2f->Scale(factor/h2f->GetEntries());
    
    cout << "h3a = " << h3a->GetEntries()<<endl;
    h3a->Scale(factor/h3a->GetEntries());
    cout << "h3b = " << h3b->GetEntries()<<endl;
    h3b->Scale(factor/h3b->GetEntries());
    cout << "h3c = " << h3c->GetEntries()<<endl;
    h3c->Scale(factor/h3c->GetEntries());
    cout << "h3d = " << h3d->GetEntries()<<endl;
    h3d->Scale(factor/h3d->GetEntries());
    cout << "h3e = " << h3e->GetEntries()<<endl;
    h3e->Scale(factor/h3e->GetEntries());
    cout << "h3f = " << h3f->GetEntries()<<endl;
    h3f->Scale(factor/h3f->GetEntries());
    
    
    
    h1aa[0]->Scale(factor/h1aa[0]->GetEntries());
    cout << "h1aa = " << h1aa[0]->GetEntries()<<endl;
    h1ba[0]->Scale(factor/h1ba[0]->GetEntries());
    cout << "h1ba = " << h1ba[0]->GetEntries()<<endl;
    h1ca[0]->Scale(factor/h1ca[0]->GetEntries());
    cout << "h1ca = " << h1ca[0]->GetEntries()<<endl;
    
    cout << "h2aa = " << h2aa[0]->GetEntries()<<endl;
   h2aa[0]->Scale(factor/h2aa[0]->GetEntries());
    cout << "h2ba = " << h2ba[0]->GetEntries()<<endl;
    h2ba[0]->Scale(factor/h2ba[0]->GetEntries());
    cout << "h2ca = " << h2ca[0]->GetEntries()<<endl;
   h2ca[0]->Scale(factor/h2ca[0]->GetEntries());
    
    cout << "h3aa = " << h3aa[0]->GetEntries()<<endl;
    h3aa[0]->Scale(factor/h3aa[0]->GetEntries());
    cout << "h3ba = " << h3ba[0]->GetEntries()<<endl;
    h3ba[0]->Scale(factor/h3ba[0]->GetEntries());
    cout << "h3ca = " << h3ca[0]->GetEntries()<<endl;
    h3ca[0]->Scale(factor/h3ca[0]->GetEntries());
    
    TCanvas *c1 = new TCanvas("c1");
    c1->Divide(3,3);
    c1->cd(1);h1a->Draw("same"); h1d->Draw("same");h1aa[0]->Draw("same");
    TLegend *legend1 = new TLegend(0.67,0.7,0.89,0.88);
    legend1->AddEntry(h1a,"rec p","l");
    legend1->AddEntry(h1d,"gen p","l");
    legend1->AddEntry(h1aa[0],"data p","l");
      legend1->Draw();
  //   c1->cd(2);h1d->Draw("same");
    c1->cd(2);h1b->Draw("same"); h1e->Draw("same");h1ba[0]->Draw("same");
    TLegend *legend1b = new TLegend(0.67,0.7,0.89,0.88);
    legend1b->AddEntry(h1b,"rec eta","l");
    legend1b->AddEntry(h1e,"gen eta","l");
      legend1b->Draw();
   // c1->cd(4);h1e->Draw("same");
    c1->cd(3);h1c->Draw("same"); h1f->Draw("same");h1ca[0]->Draw("same");
    TLegend *legend1c = new TLegend(0.67,0.7,0.89,0.88);
    legend1c->AddEntry(h1c,"rec phi","l");
    legend1c->AddEntry(h1f,"gen phi","l");
      legend1c->Draw();
  //  c1->cd(6);h1f->Draw("same");
    c1->cd(4);h3a->Draw("same"); h3d->Draw("same");h3aa[0]->Draw("same");
    TLegend *legend3 = new TLegend(0.67,0.7,0.89,0.88);
    legend3->AddEntry(h3a,"rec p","l");
    legend3->AddEntry(h3d,"gen p","l");
      legend3->Draw();
   // c1->cd(8);h3d->Draw("same");
    c1->cd(5);h3b->Draw("same"); h3e->Draw("same");h3ba[0]->Draw("same");
    TLegend *legend3b = new TLegend(0.67,0.7,0.89,0.88);
    legend3b->AddEntry(h3b,"rec eta","l");
    legend3b->AddEntry(h3e,"gen pta","l");
      legend3b->Draw();
  //  c1->cd(10);h3e->Draw("same");
    c1->cd(6);h3c->Draw("same"); h3f->Draw("same");h3ca[0]->Draw("same");
    TLegend *legend3c = new TLegend(0.67,0.7,0.89,0.88);
    legend3c->AddEntry(h3c,"rec phi","l");
    legend3c->AddEntry(h3f,"gen phi","l");
      legend3c->Draw();
  //  c1->cd(12);h3f->Draw("same");
    c1->cd(7);h2a->Draw("same"); h2d->Draw("same");h2aa[0]->Draw("same");
    TLegend *legend2 = new TLegend(0.67,0.7,0.89,0.88);
    legend2->AddEntry(h2a,"rec p","l");
    legend2->AddEntry(h2d,"gen p","l");
      legend2->Draw();
   // c1->cd(14);h2d->Draw("same");
    c1->cd(8);h2b->Draw("same"); h2e->Draw("same");h2ba[0]->Draw("same");
    TLegend *legend2b = new TLegend(0.67,0.7,0.89,0.88);
    legend2b->AddEntry(h2b,"rec eta","l");
    legend2b->AddEntry(h2e,"gen pta","l");
      legend2b->Draw();
   // c1->cd(16);h2e->Draw("same");
    c1->cd(9);h2c->Draw("same"); h2f->Draw("same");h2ca[0]->Draw("same");
    TLegend *legend2c = new TLegend(0.67,0.7,0.89,0.88);
    legend2c->AddEntry(h2c,"rec phi","l");
    legend2c->AddEntry(h2f,"gen phi","l");
      legend2c->Draw();
   // c1->cd(18);h2f->Draw("same");
    
    
    //   TCanvas *c1b = new TCanvas("c1b");
    // c1b->Divide(3,3);
    // c1b->cd(1);h1d->Draw("same");
    //  c1b->cd(2);h1e->Draw("same");
    // c1b->cd(3);h1f->Draw("same");
    //  c1b->cd(4);h3d->Draw("same");
    // c1b->cd(5);h3e->Draw("same");
    //  c1b->cd(6);h3f->Draw("same");
    // c1b->cd(7);h2d->Draw("same");
    //  c1b->cd(8);h2e->Draw("same");
    // c1b->cd(9);h2f->Draw("same");
    
    
   
    del_R_gen_rec_E_g_5to10->Scale(factor/del_R_gen_rec_E_g_5to10->GetEntries());
    cout << "del_R_gen_rec_E_g_5to10 = " << del_R_gen_rec_E_g_5to10->GetEntries()<<endl;
        del_R_gen_rec_E_g_10to15->Scale(factor/del_R_gen_rec_E_g_10to15->GetEntries());
    cout << " del_R_gen_rec_E_g_10to15 = " << del_R_gen_rec_E_g_10to15->GetEntries()<<endl;
        del_R_gen_rec_E_g_15to20->Scale(factor/del_R_gen_rec_E_g_15to20->GetEntries());
    cout << "del_R_gen_rec_E_g_15to20 = " << del_R_gen_rec_E_g_15to20->GetEntries()<<endl;
        del_R_gen_rec_E_g_20to25->Scale(factor/del_R_gen_rec_E_g_20to25->GetEntries());
    cout << "del_R_gen_rec_E_g_20to25 = " << del_R_gen_rec_E_g_20to25->GetEntries()<<endl;
        del_R_gen_rec_E_g_25to30->Scale(factor/del_R_gen_rec_E_g_25to30->GetEntries());
    cout << "del_R_gen_rec_E_g_25to30 = " << del_R_gen_rec_E_g_25to30->GetEntries()<<endl;
        del_R_gen_rec_E_g_30to35->Scale(factor/del_R_gen_rec_E_g_30to35->GetEntries());
    cout << "del_R_gen_rec_E_g_30to35 = " << del_R_gen_rec_E_g_30to35->GetEntries()<<endl;
        del_R_gen_rec_E_g_35to40->Scale(factor/del_R_gen_rec_E_g_35to40->GetEntries());
    cout << "del_R_gen_rec_E_g_35to40 = " << del_R_gen_rec_E_g_35to40->GetEntries()<<endl;
        del_R_gen_rec_E_g_40to45->Scale(factor/del_R_gen_rec_E_g_40to45->GetEntries());
    cout << "del_R_gen_rec_E_g_40to45 = " << del_R_gen_rec_E_g_40to45->GetEntries()<<endl;
        del_R_gen_rec_E_g_45to50->Scale(factor/del_R_gen_rec_E_g_45to50->GetEntries());
    cout << "del_R_gen_rec_E_g_45to50 = " << del_R_gen_rec_E_g_45to50->GetEntries()<<endl;
        del_R_gen_rec_E_g_50to55->Scale(factor/del_R_gen_rec_E_g_50to55->GetEntries());
    cout << "del_R_gen_rec_E_g_50to55 = " << del_R_gen_rec_E_g_50to55->GetEntries()<<endl;
        del_R_gen_rec_E_g_55to60->Scale(factor/del_R_gen_rec_E_g_55to60->GetEntries());
    cout << "del_R_gen_rec_E_g_55to60 = " << del_R_gen_rec_E_g_55to60->GetEntries()<<endl;
    
    
    cout << "del_R_gen_rec_E_W_5to10 = " << del_R_gen_rec_E_W_5to10->GetEntries()<<endl;
        del_R_gen_rec_E_W_5to10->Scale(factor/del_R_gen_rec_E_W_5to10->GetEntries());
    cout << "del_R_gen_rec_E_W_10to15 = " << del_R_gen_rec_E_W_10to15->GetEntries()<<endl;
            del_R_gen_rec_E_W_10to15->Scale(factor/del_R_gen_rec_E_W_10to15->GetEntries());
    cout << "del_R_gen_rec_E_W_15to20 = " << del_R_gen_rec_E_W_15to20->GetEntries()<<endl;
            del_R_gen_rec_E_W_15to20->Scale(factor/del_R_gen_rec_E_W_15to20->GetEntries());
    cout << "del_R_gen_rec_E_W_20to25 = " << del_R_gen_rec_E_W_20to25->GetEntries()<<endl;
            del_R_gen_rec_E_W_20to25->Scale(factor/del_R_gen_rec_E_W_20to25->GetEntries());
    cout << "del_R_gen_rec_E_W_25to30 = " << del_R_gen_rec_E_W_25to30->GetEntries()<<endl;
            del_R_gen_rec_E_W_25to30->Scale(factor/del_R_gen_rec_E_W_25to30->GetEntries());
    cout << "del_R_gen_rec_E_W_30to35 = " << del_R_gen_rec_E_W_30to35->GetEntries()<<endl;
            del_R_gen_rec_E_W_30to35->Scale(factor/del_R_gen_rec_E_W_30to35->GetEntries());
    cout << "del_R_gen_rec_E_W_35to40 = " << del_R_gen_rec_E_W_35to40->GetEntries()<<endl;
            del_R_gen_rec_E_W_35to40->Scale(factor/del_R_gen_rec_E_W_35to40->GetEntries());
    cout << "del_R_gen_rec_E_W_40to45 = " << del_R_gen_rec_E_W_40to45->GetEntries()<<endl;
            del_R_gen_rec_E_W_40to45->Scale(factor/del_R_gen_rec_E_W_40to45->GetEntries());
    cout << "del_R_gen_rec_E_W_45to50 = " << del_R_gen_rec_E_W_45to50->GetEntries()<<endl;
            del_R_gen_rec_E_W_45to50->Scale(factor/del_R_gen_rec_E_W_45to50->GetEntries());
    cout << " del_R_gen_rec_E_W_50to55 = " <<  del_R_gen_rec_E_W_50to55->GetEntries()<<endl;
            del_R_gen_rec_E_W_50to55->Scale(factor/del_R_gen_rec_E_W_50to55->GetEntries());
    cout << "del_R_gen_rec_E_W_55to60 = " << del_R_gen_rec_E_W_55to60->GetEntries()<<endl;
            del_R_gen_rec_E_W_55to60->Scale(factor/del_R_gen_rec_E_W_55to60->GetEntries());
   
    cout << "del_R_gen_rec_W_g_5to10 = " << del_R_gen_rec_W_g_5to10->GetEntries()<<endl;
        del_R_gen_rec_W_g_5to10->Scale(factor/del_R_gen_rec_W_g_5to10->GetEntries());
    cout << "del_R_gen_rec_W_g_10to15 = " << del_R_gen_rec_W_g_10to15->GetEntries()<<endl;
            del_R_gen_rec_W_g_10to15->Scale(factor/del_R_gen_rec_W_g_10to15->GetEntries());
    cout << "del_R_gen_rec_W_g_15to20 = " << del_R_gen_rec_W_g_15to20->GetEntries()<<endl;
            del_R_gen_rec_W_g_15to20->Scale(factor/del_R_gen_rec_W_g_15to20->GetEntries());
    cout << "del_R_gen_rec_W_g_20to25 = " << del_R_gen_rec_W_g_20to25->GetEntries()<<endl;
            del_R_gen_rec_W_g_20to25->Scale(factor/del_R_gen_rec_W_g_20to25->GetEntries());
    cout << "del_R_gen_rec_W_g_25to30 = " << del_R_gen_rec_W_g_25to30->GetEntries()<<endl;
            del_R_gen_rec_W_g_25to30->Scale(factor/del_R_gen_rec_W_g_25to30->GetEntries());
    cout << "del_R_gen_rec_W_g_30to35 = " << del_R_gen_rec_W_g_30to35->GetEntries()<<endl;
            del_R_gen_rec_W_g_30to35->Scale(factor/del_R_gen_rec_W_g_30to35->GetEntries());
    cout << "del_R_gen_rec_W_g_35to40 = " << del_R_gen_rec_W_g_35to40->GetEntries()<<endl;
            del_R_gen_rec_W_g_35to40->Scale(factor/del_R_gen_rec_W_g_35to40->GetEntries());
    cout << "del_R_gen_rec_W_g_40to45 = " << del_R_gen_rec_W_g_40to45->GetEntries()<<endl;
            del_R_gen_rec_W_g_40to45->Scale(factor/del_R_gen_rec_W_g_40to45->GetEntries());
    cout << "del_R_gen_rec_W_g_45to50 = " << del_R_gen_rec_W_g_45to50->GetEntries()<<endl;
            del_R_gen_rec_W_g_45to50->Scale(factor/del_R_gen_rec_W_g_45to50->GetEntries());
    cout << "del_R_gen_rec_W_g_50to55 = " << del_R_gen_rec_W_g_50to55->GetEntries()<<endl;
            del_R_gen_rec_W_g_50to55->Scale(factor/del_R_gen_rec_W_g_50to55->GetEntries());
    cout << "del_R_gen_rec_W_g_55to60 = " << del_R_gen_rec_W_g_55to60->GetEntries()<<endl;
            del_R_gen_rec_W_g_55to60->Scale(factor/del_R_gen_rec_W_g_55to60->GetEntries());
        
        
        
        
    
    TCanvas *c2a = new TCanvas("c2a");
        c2a->Divide(4,3);
        c2a->cd(1);gPad->SetLogy(); del_R_gen_rec_E_g_5to10->Draw("same");del_R_gen_rec_E_W_5to10->Draw("same");del_R_gen_rec_W_g_5to10->Draw("same");
    TLegend *legend4 = new TLegend(0.67,0.7,0.89,0.88);
    legend4->AddEntry(del_R_gen_rec_E_g_5to10,"E_g","l");
    legend4->AddEntry(del_R_gen_rec_E_W_5to10,"E_W","l");
    legend4->AddEntry(del_R_gen_rec_W_g_5to10,"W_g","l");
      legend4->Draw();
        c2a->cd(2);gPad->SetLogy(); del_R_gen_rec_E_g_10to15->Draw("same");del_R_gen_rec_E_W_10to15->Draw("same");del_R_gen_rec_W_g_10to15->Draw("same");
        c2a->cd(3);gPad->SetLogy(); del_R_gen_rec_E_g_15to20->Draw("same");del_R_gen_rec_E_W_15to20->Draw("same");del_R_gen_rec_W_g_15to20->Draw("same");
        c2a->cd(4);gPad->SetLogy(); del_R_gen_rec_E_g_20to25->Draw("same");del_R_gen_rec_E_W_20to25->Draw("same");del_R_gen_rec_W_g_20to25->Draw("same");
        c2a->cd(5);gPad->SetLogy(); del_R_gen_rec_E_g_25to30->Draw("same");del_R_gen_rec_E_W_25to30->Draw("same");del_R_gen_rec_W_g_25to30->Draw("same");
        c2a->cd(6);gPad->SetLogy(); del_R_gen_rec_E_g_30to35->Draw("same");del_R_gen_rec_E_W_30to35->Draw("same");del_R_gen_rec_W_g_30to35->Draw("same");
        c2a->cd(7);gPad->SetLogy(); del_R_gen_rec_E_g_35to40->Draw("same");del_R_gen_rec_E_W_35to40->Draw("same");del_R_gen_rec_W_g_35to40->Draw("same");
        c2a->cd(8);gPad->SetLogy(); del_R_gen_rec_E_g_40to45->Draw("same");del_R_gen_rec_E_W_40to45->Draw("same");del_R_gen_rec_W_g_40to45->Draw("same");
        c2a->cd(9);gPad->SetLogy(); del_R_gen_rec_E_g_45to50->Draw("same");del_R_gen_rec_E_W_45to50->Draw("same");del_R_gen_rec_W_g_45to50->Draw("same");
        c2a->cd(10);gPad->SetLogy(); del_R_gen_rec_E_g_50to55->Draw("same");del_R_gen_rec_E_W_50to55->Draw("same");del_R_gen_rec_W_g_50to55->Draw("same");
        c2a->cd(11);gPad->SetLogy(); del_R_gen_rec_E_g_55to60->Draw("same");del_R_gen_rec_E_W_55to60->Draw("same");del_R_gen_rec_W_g_55to60->Draw("same");
        
    TCanvas *c2aa = new TCanvas("c2aa");
        c2aa->Divide(4,3);
    c2aa->cd(1); del_R2_gen_rec_E_g_5to10->Draw();
    c2aa->cd(2); del_R2_gen_rec_E_g_10to15->Draw();
    c2aa->cd(3); del_R2_gen_rec_E_g_15to20->Draw();
    c2aa->cd(4); del_R2_gen_rec_E_g_20to25->Draw();
    c2aa->cd(5); del_R2_gen_rec_E_g_25to30->Draw();
    c2aa->cd(6); del_R2_gen_rec_E_g_30to35->Draw();
    c2aa->cd(7); del_R2_gen_rec_E_g_35to40->Draw();
    c2aa->cd(8); del_R2_gen_rec_E_g_40to45->Draw();
    c2aa->cd(9); del_R2_gen_rec_E_g_45to50->Draw();
    c2aa->cd(10);del_R2_gen_rec_E_g_50to55->Draw();
    c2aa->cd(11);del_R2_gen_rec_E_g_55to60->Draw();

   
    TCanvas *c2aaa = new TCanvas("c2aaa");
        c2aaa->Divide(4,3);
    c2aaa->cd(1); del_R2_gen_rec_E_W_5to10->Draw();
    c2aaa->cd(2); del_R2_gen_rec_E_W_10to15->Draw();
    c2aaa->cd(3); del_R2_gen_rec_E_W_15to20->Draw();
    c2aaa->cd(4); del_R2_gen_rec_E_W_20to25->Draw();
    c2aaa->cd(5); del_R2_gen_rec_E_W_25to30->Draw();
    c2aaa->cd(6); del_R2_gen_rec_E_W_30to35->Draw();
    c2aaa->cd(7); del_R2_gen_rec_E_W_35to40->Draw();
    c2aaa->cd(8); del_R2_gen_rec_E_W_40to45->Draw();
    c2aaa->cd(9); del_R2_gen_rec_E_W_45to50->Draw();
    c2aaa->cd(10);del_R2_gen_rec_E_W_50to55->Draw();
    c2aaa->cd(11);del_R2_gen_rec_E_W_55to60->Draw();
    
    TCanvas *c2aaaa = new TCanvas("c2aaaa");
        c2aaaa->Divide(4,3);
    c2aaaa->cd(1); del_R2_gen_rec_W_g_5to10->Draw();
    c2aaaa->cd(2); del_R2_gen_rec_W_g_10to15->Draw();
    c2aaaa->cd(3); del_R2_gen_rec_W_g_15to20->Draw();
    c2aaaa->cd(4); del_R2_gen_rec_W_g_20to25->Draw();
    c2aaaa->cd(5); del_R2_gen_rec_W_g_25to30->Draw();
    c2aaaa->cd(6); del_R2_gen_rec_W_g_30to35->Draw();
    c2aaaa->cd(7); del_R2_gen_rec_W_g_35to40->Draw();
    c2aaaa->cd(8); del_R2_gen_rec_W_g_40to45->Draw();
    c2aaaa->cd(9); del_R2_gen_rec_W_g_45to50->Draw();
    c2aaaa->cd(10);del_R2_gen_rec_W_g_50to55->Draw();
    c2aaaa->cd(11);del_R2_gen_rec_W_g_55to60->Draw();
     
    TCanvas *c2b = new TCanvas("c2b");
    c2b->Divide(1,2);
    c2b->cd(1); gPad->SetLogy(); hsphericity->Draw("same");
    c2b->cd(2); htheta->Draw("same");
    // h3[0]->Add(h3[1]);  h3[0]->Add(h3[2]); h3[0]->Add(h3[3]);  h3[0]->Add(h3[4]); h3[0]->Add(h3[5]);  h3[0]->Draw();

    TCanvas *c3a = new TCanvas("c3a");
    c3a->cd();p_vs_theta->Draw("COLZ");
    // h4[0]->Add(h4[1]); h4[0]->Add(h4[2]); h4[0]->Add(h4[3]); h4[0]->Add(h4[4]); h4[0]->Add(h4[5]);h4[0]->Draw();

    TCanvas *c3b = new TCanvas("c3b");
    // h5[0]->Add(h5[1]); h5[0]->Add(h5[2]); h5[0]->Add(h5[3]); h5[0]->Add(h5[4]); h5[0]->Add(h5[5]); h5[0]->Draw();

    cout << "h9 = " << h9->GetEntries()<<endl;
    h9->Scale(factor/h9->GetEntries());
    cout << "h9b = " << h9b->GetEntries()<<endl;
    h9b->Scale(factor/h9b->GetEntries());
    
    cout << "h6_5to10 = " << h6_5to10->GetEntries()<<endl;
    h6_5to10->Scale(factor/h6_5to10->GetEntries());
    cout << "h6_10to15 = " << h6_10to15->GetEntries()<<endl;
    h6_10to15->Scale(factor/h6_10to15->GetEntries());
    cout << "h6_15to20 = " << h6_15to20->GetEntries()<<endl;
    h6_15to20->Scale(factor/h6_15to20->GetEntries());
    cout << "h6_20to25 = " << h6_20to25->GetEntries()<<endl;
    h6_20to25->Scale(factor/h6_20to25->GetEntries());
    cout << "h6_25to30 = " << h6_25to30->GetEntries()<<endl;
    h6_25to30->Scale(factor/h6_25to30->GetEntries());
    cout << "h6_30to35 = " << h6_30to35->GetEntries()<<endl;
    h6_30to35->Scale(factor/h6_30to35->GetEntries());
    cout << "h6_35to40 = " << h6_35to40->GetEntries()<<endl;
    h6_35to40->Scale(factor/h6_35to40->GetEntries());
    cout << "h6_40to45 = " << h6_40to45->GetEntries()<<endl;
    h6_40to45->Scale(factor/h6_40to45->GetEntries());
    cout << "h6_45to50 = " << h6_45to50->GetEntries()<<endl;
    h6_45to50->Scale(factor/h6_45to50->GetEntries());
    cout << "h6_50to55 = " << h6_50to55->GetEntries()<<endl;
    h6_50to55->Scale(factor/h6_50to55->GetEntries());
    cout << "h6_55to60 = " << h6_55to60->GetEntries()<<endl;
    h6_55to60->Scale(factor/h6_55to60->GetEntries());
    
    cout << "h6b_5to10 = " << h6b_5to10->GetEntries()<<endl;
    h6b_5to10->Scale(factor/h6b_5to10->GetEntries());
    cout << "h6b_10to15 = " << h6b_10to15->GetEntries()<<endl;
    h6b_10to15->Scale(factor/h6b_10to15->GetEntries());
    cout << "h6b_15to20 = " << h6b_15to20->GetEntries()<<endl;
    h6b_15to20->Scale(factor/h6b_15to20->GetEntries());
    cout << "h6b_20to25 = " << h6b_20to25->GetEntries()<<endl;
    h6b_20to25->Scale(factor/h6b_20to25->GetEntries());
    cout << "h6b_25to30 = " << h6b_25to30->GetEntries()<<endl;
    h6b_25to30->Scale(factor/h6b_25to30->GetEntries());
    cout << "h6b_30to35 = " << h6b_30to35->GetEntries()<<endl;
    h6b_30to35->Scale(factor/h6b_30to35->GetEntries());
    cout << "h6b_35to40 = " << h6b_35to40->GetEntries()<<endl;
    h6b_35to40->Scale(factor/h6b_35to40->GetEntries());
    cout << "h6b_40to45 = " << h6b_40to45->GetEntries()<<endl;
    h6b_40to45->Scale(factor/h6b_40to45->GetEntries());
    cout << "h6b_45to50 = " << h6b_45to50->GetEntries()<<endl;
    h6b_45to50->Scale(factor/h6b_45to50->GetEntries());
    cout << "h6b_50to55 = " << h6b_50to55->GetEntries()<<endl;
    h6b_50to55->Scale(factor/h6b_50to55->GetEntries());
    cout << "h6b_55to60 = " << h6b_55to60->GetEntries()<<endl;
    h6b_55to60->Scale(factor/h6b_55to60->GetEntries());
    
    
  
    
    cout << "h7_5to10 = " << h7_5to10->GetEntries()<<endl;
    h7_5to10->Scale(factor/h7_5to10->GetEntries());
    cout << "h7_10to15 = " << h7_10to15->GetEntries()<<endl;
    h7_10to15->Scale(factor/h7_10to15->GetEntries());
    cout << "h7_15to20 = " << h7_15to20->GetEntries()<<endl;
    h7_15to20->Scale(factor/h7_15to20->GetEntries());
    cout << "h7_20to25 = " << h7_20to25->GetEntries()<<endl;
    h7_20to25->Scale(factor/h7_20to25->GetEntries());
    cout << "h7_25to30 = " << h7_25to30->GetEntries()<<endl;
    h7_25to30->Scale(factor/h7_25to30->GetEntries());
    cout << "h7_30to35 = " << h7_30to35->GetEntries()<<endl;
    h7_30to35->Scale(factor/h7_30to35->GetEntries());
    cout << "h7_35to40 = " << h7_35to40->GetEntries()<<endl;
    h7_35to40->Scale(factor/h7_35to40->GetEntries());
    cout << "h7_40to45 = " << h7_40to45->GetEntries()<<endl;
    h7_40to45->Scale(factor/h7_40to45->GetEntries());
    cout << "h7_45to50 = " << h7_45to50->GetEntries()<<endl;
    h7_45to50->Scale(factor/h7_45to50->GetEntries());
    cout << "h7_50to55 = " << h7_50to55->GetEntries()<<endl;
    h7_50to55->Scale(factor/h7_50to55->GetEntries());
    cout << "h7_55to60 = " << h7_55to60->GetEntries()<<endl;
    h7_55to60->Scale(factor/h7_55to60->GetEntries());
    
    cout << "h7b_5to10 = " << h7b_5to10->GetEntries()<<endl;
    h7b_5to10->Scale(factor/h7b_5to10->GetEntries());
    cout << "h7b_10to15 = " << h7b_10to15->GetEntries()<<endl;
    h7b_10to15->Scale(factor/h7b_10to15->GetEntries());
    cout << "h7b_15to20 = " << h7b_15to20->GetEntries()<<endl;
    h7b_15to20->Scale(factor/h7b_15to20->GetEntries());
    cout << "h7b_20to25 = " << h7b_20to25->GetEntries()<<endl;
    h7b_20to25->Scale(factor/h7b_20to25->GetEntries());
    cout << "h7b_25to30 = " << h7b_25to30->GetEntries()<<endl;
    h7b_25to30->Scale(factor/h7b_25to30->GetEntries());
    cout << "h7b_30to35 = " << h7b_30to35->GetEntries()<<endl;
    h7b_30to35->Scale(factor/h7b_30to35->GetEntries());
    cout << "h7b_35to40 = " << h7b_35to40->GetEntries()<<endl;
    h7b_35to40->Scale(factor/h7b_35to40->GetEntries());
    cout << "h7b_40to45 = " << h7b_40to45->GetEntries()<<endl;
    h7b_40to45->Scale(factor/h7b_40to45->GetEntries());
    cout << "h7b_45to50 = " << h7b_45to50->GetEntries()<<endl;
    h7b_45to50->Scale(factor/h7b_45to50->GetEntries());
    cout << "h7b_50to55 = " << h7b_50to55->GetEntries()<<endl;
    h7b_50to55->Scale(factor/h7b_50to55->GetEntries());
    cout << "h7b_55to60 = " << h7b_55to60->GetEntries()<<endl;
    h7b_55to60->Scale(factor/h7b_55to60->GetEntries());
    
  
    
    cout << "h8_5to10 = " << h8_5to10->GetEntries()<<endl;
    h8_5to10->Scale(factor/h8_5to10->GetEntries());
    cout << "h8_10to15 = " << h8_10to15->GetEntries()<<endl;
    h8_10to15->Scale(factor/h8_10to15->GetEntries());
    cout << "h8_15to20 = " << h8_15to20->GetEntries()<<endl;
    h8_15to20->Scale(factor/h8_15to20->GetEntries());
    cout << "h8_20to25 = " << h8_20to25->GetEntries()<<endl;
    h8_20to25->Scale(factor/h8_20to25->GetEntries());
    cout << "h8_25to30 = " << h8_25to30->GetEntries()<<endl;
    h8_25to30->Scale(factor/h8_25to30->GetEntries());
    cout << "h8_30to35 = " << h8_30to35->GetEntries()<<endl;
    h8_30to35->Scale(factor/h8_30to35->GetEntries());
    cout << "h8_35to40 = " << h8_35to40->GetEntries()<<endl;
    h8_35to40->Scale(factor/h8_35to40->GetEntries());
    cout << "h8_40to45 = " << h8_40to45->GetEntries()<<endl;
    h8_40to45->Scale(factor/h8_40to45->GetEntries());
    cout << "h8_45to50 = " << h8_45to50->GetEntries()<<endl;
    h8_45to50->Scale(factor/h8_45to50->GetEntries());
    cout << "h8_50to55 = " << h8_50to55->GetEntries()<<endl;
    h8_50to55->Scale(factor/h8_50to55->GetEntries());
    cout << "h8_55to60 = " << h8_55to60->GetEntries()<<endl;
    h8_55to60->Scale(factor/h8_55to60->GetEntries());
    
    cout << "h8b_5to10 = " << h8b_5to10->GetEntries()<<endl;
    h8b_5to10->Scale(factor/h8b_5to10->GetEntries());
    cout << "h8b_10to15 = " << h8b_10to15->GetEntries()<<endl;
    h8b_10to15->Scale(factor/h8b_10to15->GetEntries());
    cout << "h8b_15to20 = " << h8b_15to20->GetEntries()<<endl;
    h8b_15to20->Scale(factor/h8b_15to20->GetEntries());
    cout << "h8b_20to25 = " << h8b_20to25->GetEntries()<<endl;
    h8b_20to25->Scale(factor/h8b_20to25->GetEntries());
    cout << "h8b_25to30 = " << h8b_25to30->GetEntries()<<endl;
    h8b_25to30->Scale(factor/h8b_25to30->GetEntries());
    cout << "h8b_30to35 = " << h8b_30to35->GetEntries()<<endl;
    h8b_30to35->Scale(factor/h8b_30to35->GetEntries());
    cout << "h8b_35to40 = " << h8b_35to40->GetEntries()<<endl;
    h8b_35to40->Scale(factor/h8b_35to40->GetEntries());
    cout << "h8b_40to45 = " << h8b_40to45->GetEntries()<<endl;
    h8b_40to45->Scale(factor/h8b_40to45->GetEntries());
    cout << "h8b_45to50 = " << h8b_45to50->GetEntries()<<endl;
    h8b_45to50->Scale(factor/h8b_45to50->GetEntries());
    cout << "h8b_50to55 = " << h8b_50to55->GetEntries()<<endl;
    h8b_50to55->Scale(factor/h8b_50to55->GetEntries());
    cout << "h8b_55to60 = " << h8b_55to60->GetEntries()<<endl;
    h8b_55to60->Scale(factor/h8b_55to60->GetEntries());
    
    
   
    cout << "h12_5to10 = " << h12_5to10->GetEntries()<<endl;
    h12_5to10->Scale(factor/h12_5to10->GetEntries());
    cout << "h12_10to15 = " << h12_10to15->GetEntries()<<endl;
    h12_10to15->Scale(factor/h12_10to15->GetEntries());
    cout << "h12_15to20 = " << h12_15to20->GetEntries()<<endl;
    h12_15to20->Scale(factor/h12_15to20->GetEntries());
    cout << "h12_20to25 = " << h12_20to25->GetEntries()<<endl;
    h12_20to25->Scale(factor/h12_20to25->GetEntries());
    cout << "h12_25to30 = " << h12_25to30->GetEntries()<<endl;
    h12_25to30->Scale(factor/h12_25to30->GetEntries());
    cout << "h12_30to35 = " << h12_30to35->GetEntries()<<endl;
    h12_30to35->Scale(factor/h12_30to35->GetEntries());
    cout << "h12_35to40 = " << h12_35to40->GetEntries()<<endl;
    h12_35to40->Scale(factor/h12_35to40->GetEntries());
    cout << "h12_40to45 = " << h12_40to45->GetEntries()<<endl;
    h12_40to45->Scale(factor/h12_40to45->GetEntries());
    cout << "h12_45to50 = " << h12_45to50->GetEntries()<<endl;
    h12_45to50->Scale(factor/h12_45to50->GetEntries());
    cout << "h12_50to55 = " << h12_50to55->GetEntries()<<endl;
    h12_50to55->Scale(factor/h12_50to55->GetEntries());
    cout << "h12_55to60 = " << h12_55to60->GetEntries()<<endl;
    h12_55to60->Scale(factor/h12_55to60->GetEntries());
    
    cout << "h12b_5to10 = " << h12b_5to10->GetEntries()<<endl;
    h12b_5to10->Scale(factor/h12b_5to10->GetEntries());
    cout << "h12b_10to15 = " << h12b_10to15->GetEntries()<<endl;
    h12b_10to15->Scale(factor/h12b_10to15->GetEntries());
    cout << "h12b_15to20 = " << h12b_15to20->GetEntries()<<endl;
    h12b_15to20->Scale(factor/h12b_15to20->GetEntries());
    cout << "h12b_20to25 = " << h12b_20to25->GetEntries()<<endl;
    h12b_20to25->Scale(factor/h12b_20to25->GetEntries());
    cout << "h12b_25to30 = " << h12b_25to30->GetEntries()<<endl;
    h12b_25to30->Scale(factor/h12b_25to30->GetEntries());
    cout << "h12b_30to35 = " << h12b_30to35->GetEntries()<<endl;
    h12b_30to35->Scale(factor/h12b_30to35->GetEntries());
    cout << "h12b_35to40 = " << h12b_35to40->GetEntries()<<endl;
    h12b_35to40->Scale(factor/h12b_35to40->GetEntries());
    cout << "h12b_40to45 = " << h12b_40to45->GetEntries()<<endl;
    h12b_40to45->Scale(factor/h12b_40to45->GetEntries());
    cout << "h12b_45to50 = " << h12b_45to50->GetEntries()<<endl;
    h12b_45to50->Scale(factor/h12b_45to50->GetEntries());
    cout << "h12b_50to55 = " << h12b_50to55->GetEntries()<<endl;
    h12b_50to55->Scale(factor/h12b_50to55->GetEntries());
    cout << "h12b_55to60 = " << h12b_55to60->GetEntries()<<endl;
    h12b_55to60->Scale(factor/h12b_55to60->GetEntries());
    
    
   
    
    cout << "h13_5to10 = " << h13_5to10->GetEntries()<<endl;
    h13_5to10->Scale(factor/h13_5to10->GetEntries());
    cout << "h13_10to15 = " << h13_10to15->GetEntries()<<endl;
    h13_10to15->Scale(factor/h13_10to15->GetEntries());
    cout << "h13_15to20 = " << h13_15to20->GetEntries()<<endl;
    h13_15to20->Scale(factor/h13_15to20->GetEntries());
    cout << "h13_20to25 = " << h13_20to25->GetEntries()<<endl;
    h13_20to25->Scale(factor/h13_20to25->GetEntries());
    cout << "h13_25to30 = " << h13_25to30->GetEntries()<<endl;
    h13_25to30->Scale(factor/h13_25to30->GetEntries());
    cout << "h13_30to35 = " << h13_30to35->GetEntries()<<endl;
    h13_30to35->Scale(factor/h13_30to35->GetEntries());
    cout << "h13_35to40 = " << h13_35to40->GetEntries()<<endl;
    h13_35to40->Scale(factor/h13_35to40->GetEntries());
    cout << "h13_40to45 = " << h13_40to45->GetEntries()<<endl;
    h13_40to45->Scale(factor/h13_40to45->GetEntries());
    cout << "h13_45to50 = " << h13_45to50->GetEntries()<<endl;
    h13_45to50->Scale(factor/h13_45to50->GetEntries());
    cout << "h13_50to55 = " << h13_50to55->GetEntries()<<endl;
    h13_50to55->Scale(factor/h13_50to55->GetEntries());
    cout << "h13_55to60 = " << h13_55to60->GetEntries()<<endl;
    h13_55to60->Scale(factor/h13_55to60->GetEntries());
    
    cout << "h13b_5to10 = " << h13b_5to10->GetEntries()<<endl;
    h13b_5to10->Scale(factor/h13b_5to10->GetEntries());
    cout << "h13b_10to15 = " << h13b_10to15->GetEntries()<<endl;
    h13b_10to15->Scale(factor/h13b_10to15->GetEntries());
    cout << "h13b_15to20 = " << h13b_15to20->GetEntries()<<endl;
    h13b_15to20->Scale(factor/h13b_15to20->GetEntries());
    cout << "h13b_20to25 = " << h13b_20to25->GetEntries()<<endl;
    h13b_20to25->Scale(factor/h13b_20to25->GetEntries());
    cout << "h13b_25to30 = " << h13b_25to30->GetEntries()<<endl;
    h13b_25to30->Scale(factor/h13b_25to30->GetEntries());
    cout << "h13b_30to35 = " << h13b_30to35->GetEntries()<<endl;
    h13b_30to35->Scale(factor/h13b_30to35->GetEntries());
    cout << "h13b_35to40 = " << h13b_35to40->GetEntries()<<endl;
    h13b_35to40->Scale(factor/h13b_35to40->GetEntries());
    cout << "h13b_40to45 = " << h13b_40to45->GetEntries()<<endl;
    h13b_40to45->Scale(factor/h13b_40to45->GetEntries());
    cout << "h13b_45to50 = " << h13b_45to50->GetEntries()<<endl;
    h13b_45to50->Scale(factor/h13b_45to50->GetEntries());
    cout << "h13b_50to55 = " << h13b_50to55->GetEntries()<<endl;
    h13b_50to55->Scale(factor/h13b_50to55->GetEntries());
    cout << "h13b_55to60 = " << h13b_55to60->GetEntries()<<endl;
    h13b_55to60->Scale(factor/h13b_55to60->GetEntries());
    
  
  
    
    cout << "h14_5to10 = " << h14_5to10->GetEntries() << endl;
    h14_5to10->Scale(factor/h14_5to10->GetEntries());
    cout << "h14_10to15 = " << h14_10to15->GetEntries() << endl;
    h14_10to15->Scale(factor/h14_10to15->GetEntries());
    cout << "h14_15to20 = " << h14_15to20->GetEntries() << endl;
    h14_15to20->Scale(factor/h14_15to20->GetEntries());
    cout << "h14_20to25 = " << h14_20to25->GetEntries() << endl;
    h14_20to25->Scale(factor/h14_20to25->GetEntries());
    cout << "h14_25to30 = " << h14_25to30->GetEntries() << endl;
    h14_25to30->Scale(factor/h14_25to30->GetEntries());
    cout << "h14_30to35 = " << h14_30to35->GetEntries() << endl;
    h14_30to35->Scale(factor/h14_30to35->GetEntries());
    cout << "h14_35to40 = " << h14_35to40->GetEntries() << endl;
    h14_35to40->Scale(factor/h14_35to40->GetEntries());
    cout << "h14_40to45 = " << h14_40to45->GetEntries() << endl;
    h14_40to45->Scale(factor/h14_40to45->GetEntries());
    cout << "h14_45to50 = " << h14_45to50->GetEntries() << endl;
    h14_45to50->Scale(factor/h14_45to50->GetEntries());
    cout << "h14_50to55 = " << h14_50to55->GetEntries() << endl;
    h14_50to55->Scale(factor/h14_50to55->GetEntries());
    cout << "h14_55to60 = " << h14_55to60->GetEntries() << endl;
    h14_55to60->Scale(factor/h14_55to60->GetEntries());
    
    cout << "h14b_5to10 = " << h14b_5to10->GetEntries() << endl;
    h14b_5to10->Scale(factor/h14b_5to10->GetEntries());
    cout << "h14b_10to15 = " << h14b_10to15->GetEntries() << endl;
    h14b_10to15->Scale(factor/h14b_10to15->GetEntries());
    cout << "h14b_15to20 = " << h14b_15to20->GetEntries() << endl;
    h14b_15to20->Scale(factor/h14b_15to20->GetEntries());
    cout << "h14b_20to25 = " << h14b_20to25->GetEntries() << endl;
    h14b_20to25->Scale(factor/h14b_20to25->GetEntries());
    cout << "h14b_25to30 = " << h14b_25to30->GetEntries() << endl;
    h14b_25to30->Scale(factor/h14b_25to30->GetEntries());
    cout << "h14b_30to35 = " << h14b_30to35->GetEntries() << endl;
    h14b_30to35->Scale(factor/h14b_30to35->GetEntries());
    cout << "h14b_35to40 = " << h14b_35to40->GetEntries() << endl;
    h14b_35to40->Scale(factor/h14b_35to40->GetEntries());
    cout << "h14b_40to45 = " << h14b_40to45->GetEntries() << endl;
    h14b_40to45->Scale(factor/h14b_40to45->GetEntries());
    cout << "h14b_45to50 = " << h14b_45to50->GetEntries() << endl;
    h14b_45to50->Scale(factor/h14b_45to50->GetEntries());
    cout << "h14b_50to55 = " << h14b_50to55->GetEntries() << endl;
    h14b_50to55->Scale(factor/h14b_50to55->GetEntries());
    cout << "h14b_55to60 = " << h14b_55to60->GetEntries() << endl;
    h14b_55to60->Scale(factor/h14b_55to60->GetEntries());
    
       
    
    cout << "h15_5to10 = " << h15_5to10->GetEntries() << endl;
    h15_5to10->Scale(factor/h15_5to10->GetEntries());
    cout << "h15_10to15 = " << h15_10to15->GetEntries() << endl;
    h15_10to15->Scale(factor/h15_10to15->GetEntries());
    cout << "h15_15to20 = " << h15_15to20->GetEntries() << endl;
    h15_15to20->Scale(factor/h15_15to20->GetEntries());
    cout << "h15_20to25 = " << h15_20to25->GetEntries() << endl;
    h15_20to25->Scale(factor/h15_20to25->GetEntries());
    cout << "h15_25to30 = " << h15_25to30->GetEntries() << endl;
    h15_25to30->Scale(factor/h15_25to30->GetEntries());
    cout << "h15_30to35 = " << h15_30to35->GetEntries() << endl;
    h15_30to35->Scale(factor/h15_30to35->GetEntries());
    cout << "h15_35to40 = " << h15_35to40->GetEntries() << endl;
    h15_35to40->Scale(factor/h15_35to40->GetEntries());
    cout << "h15_40to45 = " << h15_40to45->GetEntries() << endl;
    h15_40to45->Scale(factor/h15_40to45->GetEntries());
    cout << "h15_45to50 = " << h15_45to50->GetEntries() << endl;
    h15_45to50->Scale(factor/h15_45to50->GetEntries());
    cout << "h15_50to55 = " << h15_50to55->GetEntries() << endl;
    h15_50to55->Scale(factor/h15_50to55->GetEntries());
    cout << "h15_55to60 = " << h15_55to60->GetEntries() << endl;
    h15_55to60->Scale(factor/h15_55to60->GetEntries());
    
    cout << "h15b_5to10 = " << h15b_5to10->GetEntries() << endl;
    h15b_5to10->Scale(factor/h15b_5to10->GetEntries());
    cout << "h15b_10to15 = " << h15b_10to15->GetEntries() << endl;
    h15b_10to15->Scale(factor/h15b_10to15->GetEntries());
    cout << "h15b_15to20 = " << h15b_15to20->GetEntries() << endl;
    h15b_15to20->Scale(factor/h15b_15to20->GetEntries());
    cout << "h15b_20to25 = " << h15b_20to25->GetEntries() << endl;
    h15b_20to25->Scale(factor/h15b_20to25->GetEntries());
    cout << "h15b_25to30 = " << h15b_25to30->GetEntries() << endl;
    h15b_25to30->Scale(factor/h15b_25to30->GetEntries());
    cout << "h15b_30to35 = " << h15b_30to35->GetEntries() << endl;
    h15b_30to35->Scale(factor/h15b_30to35->GetEntries());
    cout << "h15b_35to40 = " << h15b_35to40->GetEntries() << endl;
    h15b_35to40->Scale(factor/h15b_35to40->GetEntries());
    cout << "h15b_40to45 = " << h15b_40to45->GetEntries() << endl;
    h15b_40to45->Scale(factor/h15b_40to45->GetEntries());
    cout << "h15b_45to50 = " << h15b_45to50->GetEntries() << endl;
    h15b_45to50->Scale(factor/h15b_45to50->GetEntries());
    cout << "h15b_50to55 = " << h15b_50to55->GetEntries() << endl;
    h15b_50to55->Scale(factor/h15b_50to55->GetEntries());
    cout << "h15b_55to60 = " << h15b_55to60->GetEntries() << endl;
    h15b_55to60->Scale(factor/h15b_55to60->GetEntries());
    
      
    
    cout << "h16_5to10 = " << h16_5to10->GetEntries() << endl;
    h16_5to10->Scale(factor/h16_5to10->GetEntries());
    cout << "h16_10to15 = " << h16_10to15->GetEntries() << endl;
    h16_10to15->Scale(factor/h16_10to15->GetEntries());
    cout << "h16_15to20 = " << h16_15to20->GetEntries() << endl;
    h16_15to20->Scale(factor/h16_15to20->GetEntries());
    cout << "h16_20to25 = " << h16_20to25->GetEntries() << endl;
    h16_20to25->Scale(factor/h16_20to25->GetEntries());
    cout << "h16_25to30 = " << h16_25to30->GetEntries() << endl;
    h16_25to30->Scale(factor/h16_25to30->GetEntries());
    cout << " h16_30to35 = " <<  h16_30to35->GetEntries() << endl;
    h16_30to35->Scale(factor/h16_30to35->GetEntries());
    cout << "h16_35to40 = " << h16_35to40->GetEntries() << endl;
    h16_35to40->Scale(factor/h16_35to40->GetEntries());
    cout << "h16_40to45 = " << h16_40to45->GetEntries() << endl;
    h16_40to45->Scale(factor/h16_40to45->GetEntries());
    cout << "h16_45to50 = " << h16_45to50->GetEntries() << endl;
    h16_45to50->Scale(factor/h16_45to50->GetEntries());
    cout << "h16_50to55 = " << h16_50to55->GetEntries() << endl;
    h16_50to55->Scale(factor/h16_50to55->GetEntries());
    cout << "h16_55to60 = " << h16_55to60->GetEntries() << endl;
    h16_55to60->Scale(factor/h16_55to60->GetEntries());
    
    cout << "h16b_5to10 = " << h16b_5to10->GetEntries() << endl;
    h16b_5to10->Scale(factor/h16b_5to10->GetEntries());
    cout << "h16b_10to15 = " << h16b_10to15->GetEntries() << endl;
    h16b_10to15->Scale(factor/h16b_10to15->GetEntries());
    cout << "h16b_15to20 = " << h16b_15to20->GetEntries() << endl;
    h16b_15to20->Scale(factor/h16b_15to20->GetEntries());
    cout << " h16b_20to25 = " <<  h16b_20to25->GetEntries() << endl;
    h16b_20to25->Scale(factor/h16b_20to25->GetEntries());
    cout << "h16b_25to30 = " << h16b_25to30->GetEntries() << endl;
    h16b_25to30->Scale(factor/h16b_25to30->GetEntries());
    cout << "h16b_30to35 = " << h16b_30to35->GetEntries() << endl;
    h16b_30to35->Scale(factor/h16b_30to35->GetEntries());
    cout << "h16b_35to40 = " << h16b_35to40->GetEntries() << endl;
    h16b_35to40->Scale(factor/h16b_35to40->GetEntries());
    cout << "h16b_40to45 = " << h16b_40to45->GetEntries() << endl;
    h16b_40to45->Scale(factor/h16b_40to45->GetEntries());
    cout << "h16b_45to50 = " << h16b_45to50->GetEntries() << endl;
    h16b_45to50->Scale(factor/h16b_45to50->GetEntries());
    cout << "h16b_50to55 = " << h16b_50to55->GetEntries() << endl;
    h16b_50to55->Scale(factor/h16b_50to55->GetEntries());
    cout << "h16b_55to60 = " << h16b_55to60->GetEntries() << endl;
    h16b_55to60->Scale(factor/h16b_55to60->GetEntries());
    
      
    
    cout << "h17_5to10 = " << h17_5to10->GetEntries() << endl;
    h17_5to10->Scale(factor/h17_5to10->GetEntries());
    cout << "h17_10to15 = " << h17_10to15->GetEntries() << endl;
    h17_10to15->Scale(factor/h17_10to15->GetEntries());
    cout << "h17_15to20 = " << h17_15to20->GetEntries() << endl;
    h17_15to20->Scale(factor/h17_15to20->GetEntries());
    cout << "h17_20to25 = " << h17_20to25->GetEntries() << endl;
    h17_20to25->Scale(factor/h17_20to25->GetEntries());
    cout << "h17_25to30 = " << h17_25to30->GetEntries() << endl;
    h17_25to30->Scale(factor/h17_25to30->GetEntries());
    cout << "h17_30to35 = " << h17_30to35->GetEntries() << endl;
    h17_30to35->Scale(factor/h17_30to35->GetEntries());
    cout << "h17_35to40 = " << h17_35to40->GetEntries() << endl;
    h17_35to40->Scale(factor/h17_35to40->GetEntries());
    cout << "h17_40to45 = " << h17_40to45->GetEntries() << endl;
    h17_40to45->Scale(factor/h17_40to45->GetEntries());
    cout << "h17_45to50 = " << h17_45to50->GetEntries() << endl;
    h17_45to50->Scale(factor/h17_45to50->GetEntries());
    cout << "h17_50to55 = " << h17_50to55->GetEntries() << endl;
    h17_50to55->Scale(factor/h17_50to55->GetEntries());
    cout << "h17_55to60 = " << h17_55to60->GetEntries() << endl;
    h17_55to60->Scale(factor/h17_55to60->GetEntries());
    
    cout << "h17b_5to10 = " << h17b_5to10->GetEntries() << endl;
    h17b_5to10->Scale(factor/h17b_5to10->GetEntries());
    cout << "h17b_10to15 = " << h17b_10to15->GetEntries() << endl;
    h17b_10to15->Scale(factor/h17b_10to15->GetEntries());
    cout << "h17b_15to20 = " << h17b_15to20->GetEntries() << endl;
    h17b_15to20->Scale(factor/h17b_15to20->GetEntries());
    cout << "h17b_20to25 = " << h17b_20to25->GetEntries() << endl;
    h17b_20to25->Scale(factor/h17b_20to25->GetEntries());
    cout << "h17b_25to30 = " <<  h17b_25to30->GetEntries() << endl;
    h17b_25to30->Scale(factor/h17b_25to30->GetEntries());
    cout << "h17b_30to35 = " << h17b_30to35->GetEntries() << endl;
    h17b_30to35->Scale(factor/h17b_30to35->GetEntries());
    cout << "h17b_35to40 = " << h17b_35to40->GetEntries() << endl;
    h17b_35to40->Scale(factor/h17b_35to40->GetEntries());
    cout << "h17b_40to45 = " << h17b_40to45->GetEntries() << endl;
    h17b_40to45->Scale(factor/h17b_40to45->GetEntries());
    cout << "h17b_45to50 = " <<  h17b_45to50->GetEntries() << endl;
    h17b_45to50->Scale(factor/h17b_45to50->GetEntries());
    cout << "h17b_50to55 = " << h17b_50to55->GetEntries() << endl;
    h17b_50to55->Scale(factor/h17b_50to55->GetEntries());
    cout << "h17b_55to60 = " << h17b_55to60->GetEntries() << endl;
    h17b_55to60->Scale(factor/h17b_55to60->GetEntries());
    
       
    
    
    
    
 //   h6b->Scale(factor/h6b->GetEntries());
//    h7->Scale(factor/h7->GetEntries());
//    h7b->Scale(factor/h7b->GetEntries());
//    h8->Scale(factor/h8->GetEntries());
//    h8b->Scale(factor/h8b->GetEntries());
    cout << "h10 = " << h10->GetEntries() << endl;
    h10->Scale(factor/h10->GetEntries());
    cout << "h10b = " << h10b->GetEntries() << endl;
    h10b->Scale(factor/h10b->GetEntries());
    cout << "h11 = " << h11->GetEntries() << endl;
    h11->Scale(factor/h11->GetEntries());
    cout << "h11b = " << h11b->GetEntries() << endl;
   h11b->Scale(factor/h11b->GetEntries());
    
    h9aa[0]->Add(h9aa[1]);h9aa[0]->Add(h9aa[2]);h9aa[0]->Add(h9aa[3]); h9aa[0]->Add(h9aa[4]); h9aa[0]->Add(h9aa[5]);
    cout << "h9aa[0] = " << h9aa[0]->GetEntries() << endl;
    h9aa[0]->Scale(factor/h9aa[0]->GetEntries());
    
    h6aa_5to10[0]->Add(h6aa_5to10[1]);h6aa_5to10[0]->Add(h6aa_5to10[2]);h6aa_5to10[0]->Add(h6aa_5to10[3]); h6aa_5to10[0]->Add(h6aa_5to10[4]);
    h6aa_5to10[0]->Add(h6aa_5to10[5]);
    cout << "h6aa_5to10[0] = " << h6aa_5to10[0]->GetEntries() << endl;
    h6aa_5to10[0]->Scale(factor/h6aa_5to10[0]->GetEntries());
    
    h6aa_10to15[0]->Add(h6aa_10to15[1]);h6aa_10to15[0]->Add(h6aa_10to15[2]);h6aa_10to15[0]->Add(h6aa_10to15[3]); h6aa_10to15[0]->Add(h6aa_10to15[4]); h6aa_10to15[0]->Add(h6aa_10to15[5]);
    cout << "h6aa_10to15[0] = " << h6aa_10to15[0]->GetEntries() << endl;
    h6aa_10to15[0]->Scale(factor/h6aa_10to15[0]->GetEntries());
    
    h6aa_15to20[0]->Add(h6aa_15to20[1]);h6aa_15to20[0]->Add(h6aa_15to20[2]);h6aa_15to20[0]->Add(h6aa_15to20[3]); h6aa_15to20[0]->Add(h6aa_15to20[4]); h6aa_15to20[0]->Add(h6aa_15to20[5]);
    cout << "h6aa_15to20[0] = " << h6aa_15to20[0]->GetEntries() << endl;
    h6aa_15to20[0]->Scale(factor/h6aa_15to20[0]->GetEntries());
    
    h6aa_20to25[0]->Add(h6aa_20to25[1]);h6aa_20to25[0]->Add(h6aa_20to25[2]);h6aa_20to25[0]->Add(h6aa_20to25[3]); h6aa_20to25[0]->Add(h6aa_20to25[4]); h6aa_20to25[0]->Add(h6aa_20to25[5]);
    cout << "h6aa_20to25[0] = " << h6aa_20to25[0]->GetEntries() << endl;
    h6aa_20to25[0]->Scale(factor/h6aa_20to25[0]->GetEntries());
    
    h6aa_25to30[0]->Add(h6aa_25to30[1]);h6aa_25to30[0]->Add(h6aa_25to30[2]);h6aa_25to30[0]->Add(h6aa_25to30[3]); h6aa_25to30[0]->Add(h6aa_25to30[4]); h6aa_25to30[0]->Add(h6aa_25to30[5]);
    cout << "h6aa_25to30[0] = " << h6aa_25to30[0]->GetEntries() << endl;
    h6aa_25to30[0]->Scale(factor/h6aa_25to30[0]->GetEntries());
    
    h6aa_30to35[0]->Add(h6aa_30to35[1]);h6aa_30to35[0]->Add(h6aa_30to35[2]);h6aa_30to35[0]->Add(h6aa_30to35[3]); h6aa_30to35[0]->Add(h6aa_30to35[4]); h6aa_30to35[0]->Add(h6aa_30to35[5]);
    cout << "h6aa_30to35[0] = " << h6aa_30to35[0]->GetEntries() << endl;
    h6aa_30to35[0]->Scale(factor/h6aa_30to35[0]->GetEntries());
    
    h6aa_35to40[0]->Add(h6aa_35to40[1]);h6aa_35to40[0]->Add(h6aa_35to40[2]);h6aa_35to40[0]->Add(h6aa_35to40[3]); h6aa_35to40[0]->Add(h6aa_35to40[4]); h6aa_35to40[0]->Add(h6aa_35to40[5]);
    cout << "h6aa_35to40[0] = " << h6aa_35to40[0]->GetEntries() << endl;
    h6aa_35to40[0]->Scale(factor/h6aa_35to40[0]->GetEntries());
    
    h6aa_40to45[0]->Add(h6aa_40to45[1]);h6aa_40to45[0]->Add(h6aa_40to45[2]);h6aa_40to45[0]->Add(h6aa_40to45[3]); h6aa_40to45[0]->Add(h6aa_40to45[4]); h6aa_40to45[0]->Add(h6aa_40to45[5]);
    cout << " h6aa_40to45[0] = " <<  h6aa_40to45[0]->GetEntries() << endl;
    h6aa_40to45[0]->Scale(factor/h6aa_40to45[0]->GetEntries());
    
    h6aa_45to50[0]->Add(h6aa_45to50[1]);h6aa_45to50[0]->Add(h6aa_45to50[2]);h6aa_45to50[0]->Add(h6aa_45to50[3]); h6aa_45to50[0]->Add(h6aa_45to50[4]); h6aa_45to50[0]->Add(h6aa_45to50[5]);
    cout << "h6aa_45to50[0] = " << h6aa_45to50[0]->GetEntries() << endl;
    h6aa_45to50[0]->Scale(factor/h6aa_45to50[0]->GetEntries());
    
    h6aa_50to55[0]->Add(h6aa_50to55[1]);h6aa_50to55[0]->Add(h6aa_50to55[2]);h6aa_50to55[0]->Add(h6aa_50to55[3]); h6aa_50to55[0]->Add(h6aa_50to55[4]); h6aa_50to55[0]->Add(h6aa_50to55[5]);
    cout << "h6aa_50to55[0] = " << h6aa_50to55[0]->GetEntries() << endl;
    h6aa_50to55[0]->Scale(factor/h6aa_50to55[0]->GetEntries());
    
    h6aa_55to60[0]->Add(h6aa_55to60[1]);h6aa_55to60[0]->Add(h6aa_55to60[2]);h6aa_55to60[0]->Add(h6aa_55to60[3]); h6aa_55to60[0]->Add(h6aa_55to60[4]); h6aa_55to60[0]->Add(h6aa_55to60[5]);
    cout << "h6aa_55to60[0] = " << h6aa_55to60[0]->GetEntries() << endl;
    h6aa_55to60[0]->Scale(factor/h6aa_55to60[0]->GetEntries());
    
    h7aa_5to10[0]->Add(h7aa_5to10[1]);h7aa_5to10[0]->Add(h7aa_5to10[2]);h7aa_5to10[0]->Add(h7aa_5to10[3]); h7aa_5to10[0]->Add(h7aa_5to10[4]); h7aa_5to10[0]->Add(h7aa_5to10[5]);
    cout << "h7aa_5to10[0] = " << h7aa_5to10[0]->GetEntries() << endl;
    h7aa_5to10[0]->Scale(factor/h7aa_5to10[0]->GetEntries());
    
    h7aa_10to15[0]->Add(h7aa_10to15[1]);h7aa_10to15[0]->Add(h7aa_10to15[2]);h7aa_10to15[0]->Add(h7aa_10to15[3]); h7aa_10to15[0]->Add(h7aa_10to15[4]);
    h7aa_10to15[0]->Add(h7aa_10to15[5]);
    cout << "h7aa_10to15[0] = " << h7aa_10to15[0]->GetEntries() << endl;
    h7aa_10to15[0]->Scale(factor/h7aa_10to15[0]->GetEntries());
    
    h7aa_15to20[0]->Add(h7aa_15to20[1]);h7aa_15to20[0]->Add(h7aa_15to20[2]);h7aa_15to20[0]->Add(h7aa_15to20[3]); h7aa_15to20[0]->Add(h7aa_15to20[4]); h7aa_15to20[0]->Add(h7aa_15to20[5]);
    cout << "h7aa_15to20[0] = " << h7aa_15to20[0]->GetEntries() << endl;
    h7aa_15to20[0]->Scale(factor/h7aa_15to20[0]->GetEntries());
    
    h7aa_20to25[0]->Add(h7aa_20to25[1]);h7aa_20to25[0]->Add(h7aa_20to25[2]);h7aa_20to25[0]->Add(h7aa_20to25[3]); h7aa_20to25[0]->Add(h7aa_20to25[4]); h7aa_20to25[0]->Add(h7aa_20to25[5]);
    cout << "h7aa_20to25[0] = " << h7aa_20to25[0]->GetEntries() << endl;
    h7aa_20to25[0]->Scale(factor/h7aa_20to25[0]->GetEntries());
    
    h7aa_25to30[0]->Add(h7aa_25to30[1]);h7aa_25to30[0]->Add(h7aa_25to30[2]);h7aa_25to30[0]->Add(h7aa_25to30[3]); h7aa_25to30[0]->Add(h7aa_25to30[4]); h7aa_25to30[0]->Add(h7aa_25to30[5]);
    cout << "h7aa_25to30[0] = " << h7aa_25to30[0]->GetEntries() << endl;
    h7aa_25to30[0]->Scale(factor/h7aa_25to30[0]->GetEntries());
    
    h7aa_30to35[0]->Add(h7aa_30to35[1]);h7aa_30to35[0]->Add(h7aa_30to35[2]);h7aa_30to35[0]->Add(h7aa_30to35[3]); h7aa_30to35[0]->Add(h7aa_30to35[4]); h7aa_30to35[0]->Add(h7aa_30to35[5]);
    cout << "h7aa_30to35[0] = " << h7aa_30to35[0]->GetEntries() << endl;
    h7aa_30to35[0]->Scale(factor/h7aa_30to35[0]->GetEntries());
    
    h7aa_35to40[0]->Add(h7aa_35to40[1]);h7aa_35to40[0]->Add(h7aa_35to40[2]);h7aa_35to40[0]->Add(h7aa_35to40[3]); h7aa_35to40[0]->Add(h7aa_35to40[4]); h7aa_35to40[0]->Add(h7aa_35to40[5]);
    cout << "h7aa_35to40[0] = " << h7aa_35to40[0]->GetEntries() << endl;
    h7aa_35to40[0]->Scale(factor/h7aa_35to40[0]->GetEntries());
    
    h7aa_40to45[0]->Add(h7aa_40to45[1]);h7aa_40to45[0]->Add(h7aa_40to45[2]);h7aa_40to45[0]->Add(h7aa_40to45[3]); h7aa_40to45[0]->Add(h7aa_40to45[4]); h7aa_40to45[0]->Add(h7aa_40to45[5]);
    cout << "h7aa_40to45[0] = " << h7aa_40to45[0]->GetEntries() << endl;
    h7aa_40to45[0]->Scale(factor/h7aa_40to45[0]->GetEntries());
    
    h7aa_45to50[0]->Add(h7aa_45to50[1]);h7aa_45to50[0]->Add(h7aa_45to50[2]);h7aa_45to50[0]->Add(h7aa_45to50[3]); h7aa_45to50[0]->Add(h7aa_45to50[4]); h7aa_45to50[0]->Add(h7aa_45to50[5]);
    cout << "h7aa_45to50[0] = " << h7aa_45to50[0]->GetEntries() << endl;
    h7aa_45to50[0]->Scale(factor/h7aa_45to50[0]->GetEntries());
    
    h7aa_50to55[0]->Add(h7aa_50to55[1]);h7aa_50to55[0]->Add(h7aa_50to55[2]);h7aa_50to55[0]->Add(h7aa_50to55[3]); h7aa_50to55[0]->Add(h7aa_50to55[4]); h7aa_50to55[0]->Add(h7aa_50to55[5]);
    cout << " h7aa_50to55[0] = " <<  h7aa_50to55[0]->GetEntries() << endl;
    h7aa_50to55[0]->Scale(factor/h7aa_50to55[0]->GetEntries());
    
    h7aa_55to60[0]->Add(h7aa_55to60[1]);h7aa_55to60[0]->Add(h7aa_55to60[2]);h7aa_55to60[0]->Add(h7aa_55to60[3]); h7aa_55to60[0]->Add(h7aa_55to60[4]); h7aa_55to60[0]->Add(h7aa_55to60[5]);
    cout << " h7aa_55to60[0] = " <<  h7aa_55to60[0]->GetEntries() << endl;
    h7aa_55to60[0]->Scale(factor/h7aa_55to60[0]->GetEntries());
    
    
    h8aa_5to10[0]->Add(h8aa_5to10[1]);h8aa_5to10[0]->Add(h8aa_5to10[2]);h8aa_5to10[0]->Add(h8aa_5to10[3]); h8aa_5to10[0]->Add(h8aa_5to10[4]); h8aa_5to10[0]->Add(h8aa_5to10[5]);
    cout << " h8aa_5to10[0] = " <<  h8aa_5to10[0]->GetEntries() << endl;
    h8aa_5to10[0]->Scale(factor/h8aa_5to10[0]->GetEntries());
    
    h8aa_10to15[0]->Add(h8aa_10to15[1]);h8aa_10to15[0]->Add(h8aa_10to15[2]);h8aa_10to15[0]->Add(h8aa_10to15[3]); h8aa_10to15[0]->Add(h8aa_10to15[4]); h8aa_10to15[0]->Add(h8aa_10to15[5]);
    cout << "h8aa_10to15[0] = " << h8aa_10to15[0]->GetEntries() << endl;
    h8aa_10to15[0]->Scale(factor/h8aa_10to15[0]->GetEntries());
    
    h8aa_15to20[0]->Add(h8aa_15to20[1]);h8aa_15to20[0]->Add(h8aa_15to20[2]);h8aa_15to20[0]->Add(h8aa_15to20[3]); h8aa_15to20[0]->Add(h8aa_15to20[4]); h8aa_15to20[0]->Add(h8aa_15to20[5]);
    cout << "h8aa_15to20[0] = " << h8aa_15to20[0]->GetEntries() << endl;
    h8aa_15to20[0]->Scale(factor/h8aa_15to20[0]->GetEntries());
    
    h8aa_20to25[0]->Add(h8aa_20to25[1]);h8aa_20to25[0]->Add(h8aa_20to25[2]);h8aa_20to25[0]->Add(h8aa_20to25[3]); h8aa_20to25[0]->Add(h8aa_20to25[4]); h8aa_20to25[0]->Add(h8aa_20to25[5]);
    cout << " h8aa_20to25[0] = " <<  h8aa_20to25[0]->GetEntries() << endl;
    h8aa_20to25[0]->Scale(factor/h8aa_20to25[0]->GetEntries());
    
    h8aa_25to30[0]->Add(h8aa_25to30[1]);h8aa_25to30[0]->Add(h8aa_25to30[2]);h8aa_25to30[0]->Add(h8aa_25to30[3]); h8aa_25to30[0]->Add(h8aa_25to30[4]); h8aa_25to30[0]->Add(h8aa_25to30[5]);
    cout << "h8aa_25to30[0] = " << h8aa_25to30[0]->GetEntries() << endl;
    h8aa_25to30[0]->Scale(factor/h8aa_25to30[0]->GetEntries());
    
    h8aa_30to35[0]->Add(h8aa_30to35[1]);h8aa_30to35[0]->Add(h8aa_30to35[2]);h8aa_30to35[0]->Add(h8aa_30to35[3]); h8aa_30to35[0]->Add(h8aa_30to35[4]); h8aa_30to35[0]->Add(h8aa_30to35[5]);
    cout << "h8aa_30to35[0] = " << h8aa_30to35[0]->GetEntries() << endl;
    h8aa_30to35[0]->Scale(factor/h8aa_30to35[0]->GetEntries());
    
    h8aa_35to40[0]->Add(h8aa_35to40[1]);h8aa_35to40[0]->Add(h8aa_35to40[2]);h8aa_35to40[0]->Add(h8aa_35to40[3]); h8aa_35to40[0]->Add(h8aa_35to40[4]); h8aa_35to40[0]->Add(h8aa_35to40[5]);
    cout << "h8aa_35to40[0] = " << h8aa_35to40[0]->GetEntries() << endl;
    h8aa_35to40[0]->Scale(factor/h8aa_35to40[0]->GetEntries());
    
    h8aa_40to45[0]->Add(h8aa_40to45[1]);h8aa_40to45[0]->Add(h8aa_40to45[2]);h8aa_40to45[0]->Add(h8aa_40to45[3]); h8aa_40to45[0]->Add(h8aa_40to45[4]); h8aa_40to45[0]->Add(h8aa_40to45[5]);
    cout << "h8aa_40to45[0] = " << h8aa_40to45[0]->GetEntries() << endl;
    h8aa_40to45[0]->Scale(factor/h8aa_40to45[0]->GetEntries());
    
    h8aa_45to50[0]->Add(h8aa_45to50[1]);h8aa_45to50[0]->Add(h8aa_45to50[2]);h8aa_45to50[0]->Add(h8aa_45to50[3]); h8aa_45to50[0]->Add(h8aa_45to50[4]); h8aa_45to50[0]->Add(h8aa_45to50[5]);
    cout << "h8aa_45to50[0] = " << h8aa_45to50[0]->GetEntries() << endl;
    h8aa_45to50[0]->Scale(factor/h8aa_45to50[0]->GetEntries());
    
    h8aa_50to55[0]->Add(h8aa_50to55[1]);h8aa_50to55[0]->Add(h8aa_50to55[2]);h8aa_50to55[0]->Add(h8aa_50to55[3]); h8aa_50to55[0]->Add(h8aa_50to55[4]); h8aa_50to55[0]->Add(h8aa_50to55[5]);
    cout << "h8aa_50to55[0] = " <<  h8aa_50to55[0]->GetEntries() << endl;
    h8aa_50to55[0]->Scale(factor/h8aa_50to55[0]->GetEntries());
    
    h8aa_55to60[0]->Add(h8aa_55to60[1]);h8aa_55to60[0]->Add(h8aa_55to60[2]);h8aa_55to60[0]->Add(h8aa_55to60[3]); h8aa_55to60[0]->Add(h8aa_55to60[4]); h8aa_55to60[0]->Add(h8aa_55to60[5]);
    cout << "h8aa_55to60[0] = " << h8aa_55to60[0]->GetEntries() << endl;
    h8aa_55to60[0]->Scale(factor/h8aa_55to60[0]->GetEntries());
    
    h12aa_5to10[0]->Add(h12aa_5to10[1]);h12aa_5to10[0]->Add(h12aa_5to10[2]);h12aa_5to10[0]->Add(h12aa_5to10[3]); h12aa_5to10[0]->Add(h12aa_5to10[4]); h12aa_5to10[0]->Add(h12aa_5to10[5]);
    cout << "h12aa_5to10[0] = " << h12aa_5to10[0]->GetEntries() << endl;
    h12aa_5to10[0]->Scale(factor/h12aa_5to10[0]->GetEntries());
    
    h12aa_10to15[0]->Add(h12aa_10to15[1]);h12aa_10to15[0]->Add(h12aa_10to15[2]);h12aa_10to15[0]->Add(h12aa_10to15[3]); h12aa_10to15[0]->Add(h12aa_10to15[4]); h12aa_10to15[0]->Add(h12aa_10to15[5]);
    cout << "h12aa_10to15[0] = " << h12aa_10to15[0]->GetEntries() << endl;
    h12aa_10to15[0]->Scale(factor/h12aa_10to15[0]->GetEntries());
    
    h12aa_15to20[0]->Add(h12aa_15to20[1]);h12aa_15to20[0]->Add(h12aa_15to20[2]);h12aa_15to20[0]->Add(h12aa_15to20[3]); h12aa_15to20[0]->Add(h12aa_15to20[4]); h12aa_15to20[0]->Add(h12aa_15to20[5]);
    cout << "h12aa_15to20[0] = " << h12aa_15to20[0]->GetEntries() << endl;
    h12aa_15to20[0]->Scale(factor/h12aa_15to20[0]->GetEntries());
    
    h12aa_20to25[0]->Add(h12aa_20to25[1]);h12aa_20to25[0]->Add(h12aa_20to25[2]);h12aa_20to25[0]->Add(h12aa_20to25[3]); h12aa_20to25[0]->Add(h12aa_20to25[4]); h12aa_20to25[0]->Add(h12aa_20to25[5]);
    cout << "h12aa_20to25[0] = " << h12aa_20to25[0]->GetEntries() << endl;
    h12aa_20to25[0]->Scale(factor/h12aa_20to25[0]->GetEntries());
    
    h12aa_25to30[0]->Add(h12aa_25to30[1]);h12aa_25to30[0]->Add(h12aa_25to30[2]);h12aa_25to30[0]->Add(h12aa_25to30[3]); h12aa_25to30[0]->Add(h12aa_25to30[4]); h12aa_25to30[0]->Add(h12aa_25to30[5]);
    cout << "h12aa_25to30[0] = " << h12aa_25to30[0]->GetEntries() << endl;
    h12aa_25to30[0]->Scale(factor/h12aa_25to30[0]->GetEntries());
    
    h12aa_30to35[0]->Add(h12aa_30to35[1]);h12aa_30to35[0]->Add(h12aa_30to35[2]);h12aa_30to35[0]->Add(h12aa_30to35[3]); h12aa_30to35[0]->Add(h12aa_30to35[4]); h12aa_30to35[0]->Add(h12aa_30to35[5]);
    cout << "h12aa_30to35[0] = " << h12aa_30to35[0]->GetEntries() << endl;
    h12aa_30to35[0]->Scale(factor/h12aa_30to35[0]->GetEntries());
    
    h12aa_35to40[0]->Add(h12aa_35to40[1]);h12aa_35to40[0]->Add(h12aa_35to40[2]);h12aa_35to40[0]->Add(h12aa_35to40[3]); h12aa_35to40[0]->Add(h12aa_35to40[4]); h12aa_35to40[0]->Add(h12aa_35to40[5]);
    cout << "h12aa_35to40[0] = " << h12aa_35to40[0]->GetEntries() << endl;
    h12aa_35to40[0]->Scale(factor/h12aa_35to40[0]->GetEntries());
    
    h12aa_40to45[0]->Add(h12aa_40to45[1]);h12aa_40to45[0]->Add(h12aa_40to45[2]);h12aa_40to45[0]->Add(h12aa_40to45[3]); h12aa_40to45[0]->Add(h12aa_40to45[4]); h12aa_40to45[0]->Add(h12aa_40to45[5]);
    cout << " h12aa_40to45[0] = " <<  h12aa_40to45[0]->GetEntries() << endl;
    h12aa_40to45[0]->Scale(factor/h12aa_40to45[0]->GetEntries());
    
    h12aa_45to50[0]->Add(h12aa_45to50[1]);h12aa_45to50[0]->Add(h12aa_45to50[2]);h12aa_45to50[0]->Add(h12aa_45to50[3]); h12aa_45to50[0]->Add(h12aa_45to50[4]); h12aa_45to50[0]->Add(h12aa_45to50[5]);
    cout << "h12aa_45to50[0] = " << h12aa_45to50[0]->GetEntries() << endl;
    h12aa_45to50[0]->Scale(factor/h12aa_45to50[0]->GetEntries());
    
    h12aa_50to55[0]->Add(h12aa_50to55[1]);h12aa_50to55[0]->Add(h12aa_50to55[2]);h12aa_50to55[0]->Add(h12aa_50to55[3]); h12aa_50to55[0]->Add(h12aa_50to55[4]); h12aa_50to55[0]->Add(h12aa_50to55[5]);
    cout << "h12aa_50to55[0] = " << h12aa_50to55[0]->GetEntries() << endl;
    h12aa_50to55[0]->Scale(factor/h12aa_50to55[0]->GetEntries());
    
    h12aa_55to60[0]->Add(h12aa_55to60[1]);h12aa_55to60[0]->Add(h12aa_55to60[2]);h12aa_55to60[0]->Add(h12aa_55to60[3]); h12aa_55to60[0]->Add(h12aa_55to60[4]); h12aa_55to60[0]->Add(h12aa_55to60[5]);
    cout << " h12aa_55to60[0] = " <<  h12aa_55to60[0]->GetEntries() << endl;
    h12aa_55to60[0]->Scale(factor/h12aa_55to60[0]->GetEntries());
    
    h13aa_5to10[0]->Add(h13aa_5to10[1]);h13aa_5to10[0]->Add(h13aa_5to10[2]);h13aa_5to10[0]->Add(h13aa_5to10[3]); h13aa_5to10[0]->Add(h13aa_5to10[4]); h13aa_5to10[0]->Add(h13aa_5to10[5]);
    cout << "h13aa_5to10[0] = " << h13aa_5to10[0]->GetEntries() << endl;
    h13aa_5to10[0]->Scale(factor/h13aa_5to10[0]->GetEntries());
    
    h13aa_10to15[0]->Add(h13aa_10to15[1]);h13aa_10to15[0]->Add(h13aa_10to15[2]);h13aa_10to15[0]->Add(h13aa_10to15[3]); h13aa_10to15[0]->Add(h13aa_10to15[4]); h13aa_10to15[0]->Add(h13aa_10to15[5]);
    cout << "h13aa_10to15[0] = " << h13aa_10to15[0]->GetEntries() << endl;
    h13aa_10to15[0]->Scale(factor/h13aa_10to15[0]->GetEntries());
    
    h13aa_15to20[0]->Add(h13aa_15to20[1]);h13aa_15to20[0]->Add(h13aa_15to20[2]);h13aa_15to20[0]->Add(h13aa_15to20[3]); h13aa_15to20[0]->Add(h13aa_15to20[4]); h13aa_15to20[0]->Add(h13aa_15to20[5]);
    cout << " h13aa_15to20[0] = " <<  h13aa_15to20[0]->GetEntries() << endl;
    h13aa_15to20[0]->Scale(factor/h13aa_15to20[0]->GetEntries());
    
    h13aa_20to25[0]->Add(h13aa_20to25[1]);h13aa_20to25[0]->Add(h13aa_20to25[2]);h13aa_20to25[0]->Add(h13aa_20to25[3]); h13aa_20to25[0]->Add(h13aa_20to25[4]); h13aa_20to25[0]->Add(h13aa_20to25[5]);
    cout << " h13aa_20to25[0] = " <<  h13aa_20to25[0]->GetEntries() << endl;
    h13aa_20to25[0]->Scale(factor/h13aa_20to25[0]->GetEntries());
    
    h13aa_25to30[0]->Add(h13aa_25to30[1]);h13aa_25to30[0]->Add(h13aa_25to30[2]);h13aa_25to30[0]->Add(h13aa_25to30[3]); h13aa_25to30[0]->Add(h13aa_25to30[4]); h13aa_25to30[0]->Add(h13aa_25to30[5]);
    cout << "h13aa_25to30[0] = " << h13aa_25to30[0]->GetEntries() << endl;
    h13aa_25to30[0]->Scale(factor/h13aa_25to30[0]->GetEntries());
    
    h13aa_30to35[0]->Add(h13aa_30to35[1]);h13aa_30to35[0]->Add(h13aa_30to35[2]);h13aa_30to35[0]->Add(h13aa_30to35[3]); h13aa_30to35[0]->Add(h13aa_30to35[4]); h13aa_30to35[0]->Add(h13aa_30to35[5]);
    cout << "h13aa_30to35[0] = " << h13aa_30to35[0]->GetEntries() << endl;
    h13aa_30to35[0]->Scale(factor/h13aa_30to35[0]->GetEntries());
    
    h13aa_35to40[0]->Add(h13aa_35to40[1]);h13aa_35to40[0]->Add(h13aa_35to40[2]);h13aa_35to40[0]->Add(h13aa_35to40[3]); h13aa_35to40[0]->Add(h13aa_35to40[4]); h13aa_35to40[0]->Add(h13aa_35to40[5]);
    cout << "h13aa_35to40[0] = " << h13aa_35to40[0]->GetEntries() << endl;
    h13aa_35to40[0]->Scale(factor/h13aa_35to40[0]->GetEntries());
    
    h13aa_40to45[0]->Add(h13aa_40to45[1]);h13aa_40to45[0]->Add(h13aa_40to45[2]);h13aa_40to45[0]->Add(h13aa_40to45[3]); h13aa_40to45[0]->Add(h13aa_40to45[4]); h13aa_40to45[0]->Add(h13aa_40to45[5]);
    cout << "h13aa_40to45[0] = " << h13aa_40to45[0]->GetEntries() << endl;
    h13aa_40to45[0]->Scale(factor/h13aa_40to45[0]->GetEntries());
    
    h13aa_45to50[0]->Add(h13aa_45to50[1]);h13aa_45to50[0]->Add(h13aa_45to50[2]);h13aa_45to50[0]->Add(h13aa_45to50[3]); h13aa_45to50[0]->Add(h13aa_45to50[4]); h13aa_45to50[0]->Add(h13aa_45to50[5]);
    cout << "h13aa_45to50[0] = " << h13aa_45to50[0]->GetEntries() << endl;
    h13aa_45to50[0]->Scale(factor/h13aa_45to50[0]->GetEntries());
    
    h13aa_50to55[0]->Add(h13aa_50to55[1]);h13aa_50to55[0]->Add(h13aa_50to55[2]);h13aa_50to55[0]->Add(h13aa_50to55[3]); h13aa_50to55[0]->Add(h13aa_50to55[4]); h13aa_50to55[0]->Add(h13aa_50to55[5]);
    cout << "h13aa_50to55[0] = " << h13aa_50to55[0]->GetEntries() << endl;
    h13aa_50to55[0]->Scale(factor/h13aa_50to55[0]->GetEntries());
    
    h13aa_55to60[0]->Add(h13aa_55to60[1]);h13aa_55to60[0]->Add(h13aa_55to60[2]);h13aa_55to60[0]->Add(h13aa_55to60[3]); h13aa_55to60[0]->Add(h13aa_55to60[4]); h13aa_55to60[0]->Add(h13aa_55to60[5]);
    cout << " h13aa_55to60[0] = " <<  h13aa_55to60[0]->GetEntries() << endl;
    h13aa_55to60[0]->Scale(factor/h13aa_55to60[0]->GetEntries());
    
    
    h14aa_5to10[0]->Add(h14aa_5to10[1]);h14aa_5to10[0]->Add(h14aa_5to10[2]);h14aa_5to10[0]->Add(h14aa_5to10[3]); h14aa_5to10[0]->Add(h14aa_5to10[4]); h14aa_5to10[0]->Add(h14aa_5to10[5]);
    cout << " h14aa_5to10[0] = " <<  h14aa_5to10[0]->GetEntries() << endl;
    h14aa_5to10[0]->Scale(factor/h14aa_5to10[0]->GetEntries());
    
    h14aa_10to15[0]->Add(h14aa_10to15[1]);h14aa_10to15[0]->Add(h14aa_10to15[2]);h14aa_10to15[0]->Add(h14aa_10to15[3]); h14aa_10to15[0]->Add(h14aa_10to15[4]); h14aa_10to15[0]->Add(h14aa_10to15[5]);
    cout << "h14aa_10to15[0] = " << h14aa_10to15[0]->GetEntries() << endl;
    h14aa_10to15[0]->Scale(factor/h14aa_10to15[0]->GetEntries());
    
    h14aa_15to20[0]->Add(h14aa_15to20[1]);h14aa_15to20[0]->Add(h14aa_15to20[2]);h14aa_15to20[0]->Add(h14aa_15to20[3]); h14aa_15to20[0]->Add(h14aa_15to20[4]); h14aa_15to20[0]->Add(h14aa_15to20[5]);
    cout << "h14aa_15to20[0] = " << h14aa_15to20[0]->GetEntries() << endl;
    h14aa_15to20[0]->Scale(factor/h14aa_15to20[0]->GetEntries());
    
    h14aa_20to25[0]->Add(h14aa_20to25[1]);h14aa_20to25[0]->Add(h14aa_20to25[2]);h14aa_20to25[0]->Add(h14aa_20to25[3]); h14aa_20to25[0]->Add(h14aa_20to25[4]); h14aa_20to25[0]->Add(h14aa_20to25[5]);
    cout << " h14aa_20to25[0] = " <<  h14aa_20to25[0]->GetEntries() << endl;
    h14aa_20to25[0]->Scale(factor/h14aa_20to25[0]->GetEntries());
    
    h14aa_25to30[0]->Add(h14aa_25to30[1]);h14aa_25to30[0]->Add(h14aa_25to30[2]);h14aa_25to30[0]->Add(h14aa_25to30[3]); h14aa_25to30[0]->Add(h14aa_25to30[4]); h14aa_25to30[0]->Add(h14aa_25to30[5]);
    cout << "h14aa_25to30[0] = " << h14aa_25to30[0]->GetEntries() << endl;
    h14aa_25to30[0]->Scale(factor/h14aa_25to30[0]->GetEntries());
    
    h14aa_30to35[0]->Add(h14aa_30to35[1]);h14aa_30to35[0]->Add(h14aa_30to35[2]);h14aa_30to35[0]->Add(h14aa_30to35[3]); h14aa_30to35[0]->Add(h14aa_30to35[4]); h14aa_30to35[0]->Add(h14aa_30to35[5]);
    cout << "h14aa_30to35[0] = " << h14aa_30to35[0]->GetEntries() << endl;
    h14aa_30to35[0]->Scale(factor/h14aa_30to35[0]->GetEntries());
    
    h14aa_35to40[0]->Add(h14aa_35to40[1]);h14aa_35to40[0]->Add(h14aa_35to40[2]);h14aa_35to40[0]->Add(h14aa_35to40[3]); h14aa_35to40[0]->Add(h14aa_35to40[4]); h14aa_35to40[0]->Add(h14aa_35to40[5]);
    cout << " h14aa_35to40[0] = " <<  h14aa_35to40[0]->GetEntries() << endl;
    h14aa_35to40[0]->Scale(factor/h14aa_35to40[0]->GetEntries());
    
    h14aa_40to45[0]->Add(h14aa_40to45[1]);h14aa_40to45[0]->Add(h14aa_40to45[2]);h14aa_40to45[0]->Add(h14aa_40to45[3]); h14aa_40to45[0]->Add(h14aa_40to45[4]); h14aa_40to45[0]->Add(h14aa_40to45[5]);
    cout << " h14aa_40to45[0] = " <<  h14aa_40to45[0]->GetEntries() << endl;
    h14aa_40to45[0]->Scale(factor/h14aa_40to45[0]->GetEntries());
    
    h14aa_45to50[0]->Add(h14aa_45to50[1]);h14aa_45to50[0]->Add(h14aa_45to50[2]);h14aa_45to50[0]->Add(h14aa_45to50[3]); h14aa_45to50[0]->Add(h14aa_45to50[4]); h14aa_45to50[0]->Add(h14aa_45to50[5]);
    cout << " h14aa_45to50[0] = " <<  h14aa_45to50[0]->GetEntries() << endl;
    h14aa_45to50[0]->Scale(factor/h14aa_45to50[0]->GetEntries());
    
    h14aa_50to55[0]->Add(h14aa_50to55[1]);h14aa_50to55[0]->Add(h14aa_50to55[2]);h14aa_50to55[0]->Add(h14aa_50to55[3]); h14aa_50to55[0]->Add(h14aa_50to55[4]); h14aa_50to55[0]->Add(h14aa_50to55[5]);
    cout << " h14aa_50to55[0] = " <<  h14aa_50to55[0]->GetEntries() << endl;
    h14aa_50to55[0]->Scale(factor/h14aa_50to55[0]->GetEntries());
    
    h14aa_55to60[0]->Add(h14aa_55to60[1]);h14aa_55to60[0]->Add(h14aa_55to60[2]);h14aa_55to60[0]->Add(h14aa_55to60[3]); h14aa_55to60[0]->Add(h14aa_55to60[4]); h14aa_55to60[0]->Add(h14aa_55to60[5]);
    cout << "h14aa_55to60[0] = " << h14aa_55to60[0]->GetEntries() << endl;
    h14aa_55to60[0]->Scale(factor/h14aa_55to60[0]->GetEntries());
    
    h15aa_5to10[0]->Add(h15aa_5to10[1]);h15aa_5to10[0]->Add(h15aa_5to10[2]);h15aa_5to10[0]->Add(h15aa_5to10[3]); h15aa_5to10[0]->Add(h15aa_5to10[4]); h15aa_5to10[0]->Add(h15aa_5to10[5]);
    cout << "h15aa_5to10[0] = " << h15aa_5to10[0]->GetEntries() << endl;
    h15aa_5to10[0]->Scale(factor/h15aa_5to10[0]->GetEntries());
    
    h15aa_10to15[0]->Add(h15aa_10to15[1]);h15aa_10to15[0]->Add(h15aa_10to15[2]);h15aa_10to15[0]->Add(h15aa_10to15[3]); h15aa_10to15[0]->Add(h15aa_10to15[4]); h15aa_10to15[0]->Add(h15aa_10to15[5]);
    cout << "h15aa_10to15[0] = " << h15aa_10to15[0]->GetEntries() << endl;
    h15aa_10to15[0]->Scale(factor/h15aa_10to15[0]->GetEntries());
    
    h15aa_15to20[0]->Add(h15aa_15to20[1]);h15aa_15to20[0]->Add(h15aa_15to20[2]);h15aa_15to20[0]->Add(h15aa_15to20[3]); h15aa_15to20[0]->Add(h15aa_15to20[4]); h15aa_15to20[0]->Add(h15aa_15to20[5]);
    cout << " h15aa_15to20[0] = " <<  h15aa_15to20[0]->GetEntries() << endl;
    h15aa_15to20[0]->Scale(factor/h15aa_15to20[0]->GetEntries());
    
    h15aa_20to25[0]->Add(h15aa_20to25[1]);h15aa_20to25[0]->Add(h15aa_20to25[2]);h15aa_20to25[0]->Add(h15aa_20to25[3]); h15aa_20to25[0]->Add(h15aa_20to25[4]); h15aa_20to25[0]->Add(h15aa_20to25[5]);
    cout << " h15aa_20to25[0] = " <<  h15aa_20to25[0]->GetEntries() << endl;
    h15aa_20to25[0]->Scale(factor/h15aa_20to25[0]->GetEntries());
    
    h15aa_25to30[0]->Add(h15aa_25to30[1]);h15aa_25to30[0]->Add(h15aa_25to30[2]);h15aa_25to30[0]->Add(h15aa_25to30[3]); h15aa_25to30[0]->Add(h15aa_25to30[4]); h15aa_25to30[0]->Add(h15aa_25to30[5]);
    cout << "h15aa_25to30[0] = " << h15aa_25to30[0]->GetEntries() << endl;
    h15aa_25to30[0]->Scale(factor/h15aa_25to30[0]->GetEntries());
    
    h15aa_30to35[0]->Add(h15aa_30to35[1]);h15aa_30to35[0]->Add(h15aa_30to35[2]);h15aa_30to35[0]->Add(h15aa_30to35[3]); h15aa_30to35[0]->Add(h15aa_30to35[4]); h15aa_30to35[0]->Add(h15aa_30to35[5]);
    cout << "h15aa_30to35[0] = " << h15aa_30to35[0]->GetEntries() << endl;
    h15aa_30to35[0]->Scale(factor/h15aa_30to35[0]->GetEntries());
    
    h15aa_35to40[0]->Add(h15aa_35to40[1]);h15aa_35to40[0]->Add(h15aa_35to40[2]);h15aa_35to40[0]->Add(h15aa_35to40[3]); h15aa_35to40[0]->Add(h15aa_35to40[4]); h15aa_35to40[0]->Add(h15aa_35to40[5]);
    cout << "h15aa_35to40[0] = " << h15aa_35to40[0]->GetEntries() << endl;
    h15aa_35to40[0]->Scale(factor/h15aa_35to40[0]->GetEntries());
    
    h15aa_40to45[0]->Add(h15aa_40to45[1]);h15aa_40to45[0]->Add(h15aa_40to45[2]);h15aa_40to45[0]->Add(h15aa_40to45[3]); h15aa_40to45[0]->Add(h15aa_40to45[4]); h15aa_40to45[0]->Add(h15aa_40to45[5]);
    cout << "h15aa_40to45[0] = " << h15aa_40to45[0]->GetEntries() << endl;
    h15aa_40to45[0]->Scale(factor/h15aa_40to45[0]->GetEntries());
    
    h15aa_45to50[0]->Add(h15aa_45to50[1]);h15aa_45to50[0]->Add(h15aa_45to50[2]);h15aa_45to50[0]->Add(h15aa_45to50[3]); h15aa_45to50[0]->Add(h15aa_45to50[4]); h15aa_45to50[0]->Add(h15aa_45to50[5]);
    cout << "h15aa_45to50[0] = " << h15aa_45to50[0]->GetEntries() << endl;
    h15aa_45to50[0]->Scale(factor/h15aa_45to50[0]->GetEntries());
    
    h15aa_50to55[0]->Add(h15aa_50to55[1]);h15aa_50to55[0]->Add(h15aa_50to55[2]);h15aa_50to55[0]->Add(h15aa_50to55[3]); h15aa_50to55[0]->Add(h15aa_50to55[4]); h15aa_50to55[0]->Add(h15aa_50to55[5]);
    cout << "h15aa_50to55[0] = " << h15aa_50to55[0]->GetEntries() << endl;
    h15aa_50to55[0]->Scale(factor/h15aa_50to55[0]->GetEntries());
    
    h15aa_55to60[0]->Add(h15aa_55to60[1]);h15aa_55to60[0]->Add(h15aa_55to60[2]);h15aa_55to60[0]->Add(h15aa_55to60[3]); h15aa_55to60[0]->Add(h15aa_55to60[4]); h15aa_55to60[0]->Add(h15aa_55to60[5]);
    cout << "h15aa_55to60[0] = " << h15aa_55to60[0]->GetEntries() << endl;
    h15aa_55to60[0]->Scale(factor/h15aa_55to60[0]->GetEntries());
    
    

    h16aa_5to10[0]->Add(h16aa_5to10[1]);h16aa_5to10[0]->Add(h16aa_5to10[2]);h16aa_5to10[0]->Add(h16aa_5to10[3]); h16aa_5to10[0]->Add(h16aa_5to10[4]); h16aa_5to10[0]->Add(h16aa_5to10[5]);
    cout << "h16aa_5to10[0] = " << h16aa_5to10[0]->GetEntries() << endl;
    h16aa_5to10[0]->Scale(factor/h16aa_5to10[0]->GetEntries());
    
    h16aa_10to15[0]->Add(h16aa_10to15[1]);h16aa_10to15[0]->Add(h16aa_10to15[2]);h16aa_10to15[0]->Add(h16aa_10to15[3]); h16aa_10to15[0]->Add(h16aa_10to15[4]); h16aa_10to15[0]->Add(h16aa_10to15[5]);
    cout << " h16aa_10to15[0] = " <<  h16aa_10to15[0]->GetEntries() << endl;
    h16aa_10to15[0]->Scale(factor/h16aa_10to15[0]->GetEntries());
    
    h16aa_15to20[0]->Add(h16aa_15to20[1]);h16aa_15to20[0]->Add(h16aa_15to20[2]);h16aa_15to20[0]->Add(h16aa_15to20[3]); h16aa_15to20[0]->Add(h16aa_15to20[4]); h16aa_15to20[0]->Add(h16aa_15to20[5]);
    cout << " h16aa_15to20[0] = " <<  h16aa_15to20[0]->GetEntries() << endl;
    h16aa_15to20[0]->Scale(factor/h16aa_15to20[0]->GetEntries());
    
    h16aa_20to25[0]->Add(h16aa_20to25[1]);h16aa_20to25[0]->Add(h16aa_20to25[2]);h16aa_20to25[0]->Add(h16aa_20to25[3]); h16aa_20to25[0]->Add(h16aa_20to25[4]); h16aa_20to25[0]->Add(h16aa_20to25[5]);
    cout << "h16aa_20to25[0] = " << h16aa_20to25[0]->GetEntries() << endl;
    h16aa_20to25[0]->Scale(factor/h16aa_20to25[0]->GetEntries());
    
    h16aa_25to30[0]->Add(h16aa_25to30[1]);h16aa_25to30[0]->Add(h16aa_25to30[2]);h16aa_25to30[0]->Add(h16aa_25to30[3]); h16aa_25to30[0]->Add(h16aa_25to30[4]); h16aa_25to30[0]->Add(h16aa_25to30[5]);
    cout << "h16aa_25to30[0] = " << h16aa_25to30[0]->GetEntries() << endl;
    h16aa_25to30[0]->Scale(factor/h16aa_25to30[0]->GetEntries());
    
    h16aa_30to35[0]->Add(h16aa_30to35[1]);h16aa_30to35[0]->Add(h16aa_30to35[2]);h16aa_30to35[0]->Add(h16aa_30to35[3]); h16aa_30to35[0]->Add(h16aa_30to35[4]); h16aa_30to35[0]->Add(h16aa_30to35[5]);
    cout << "h16aa_30to35[0] = " << h16aa_30to35[0]->GetEntries() << endl;
    h16aa_30to35[0]->Scale(factor/h16aa_30to35[0]->GetEntries());
    
    h16aa_35to40[0]->Add(h16aa_35to40[1]);h16aa_35to40[0]->Add(h16aa_35to40[2]);h16aa_35to40[0]->Add(h16aa_35to40[3]); h16aa_35to40[0]->Add(h16aa_35to40[4]); h16aa_35to40[0]->Add(h16aa_35to40[5]);
    cout << "h16aa_35to40[0] = " << h16aa_35to40[0]->GetEntries() << endl;
    h16aa_35to40[0]->Scale(factor/h16aa_35to40[0]->GetEntries());
    
    h16aa_40to45[0]->Add(h16aa_40to45[1]);h16aa_40to45[0]->Add(h16aa_40to45[2]);h16aa_40to45[0]->Add(h16aa_40to45[3]); h16aa_40to45[0]->Add(h16aa_40to45[4]); h16aa_40to45[0]->Add(h16aa_40to45[5]);
    cout << "h16aa_40to45[0] = " << h16aa_40to45[0]->GetEntries() << endl;
    h16aa_40to45[0]->Scale(factor/h16aa_40to45[0]->GetEntries());
    
    h16aa_45to50[0]->Add(h16aa_45to50[1]);h16aa_45to50[0]->Add(h16aa_45to50[2]);h16aa_45to50[0]->Add(h16aa_45to50[3]); h16aa_45to50[0]->Add(h16aa_45to50[4]); h16aa_45to50[0]->Add(h16aa_45to50[5]);
    cout << " h16aa_45to50[0] = " <<  h16aa_45to50[0]->GetEntries() << endl;
    h16aa_45to50[0]->Scale(factor/h16aa_45to50[0]->GetEntries());
    
    h16aa_50to55[0]->Add(h16aa_50to55[1]);h16aa_50to55[0]->Add(h16aa_50to55[2]);h16aa_50to55[0]->Add(h16aa_50to55[3]); h16aa_50to55[0]->Add(h16aa_50to55[4]); h16aa_50to55[0]->Add(h16aa_50to55[5]);
    cout << " h16aa_50to55[0] = " <<  h16aa_50to55[0]->GetEntries() << endl;
    h16aa_50to55[0]->Scale(factor/h16aa_50to55[0]->GetEntries());
    
    h16aa_55to60[0]->Add(h16aa_55to60[1]);h16aa_55to60[0]->Add(h16aa_55to60[2]);h16aa_55to60[0]->Add(h16aa_55to60[3]); h16aa_55to60[0]->Add(h16aa_55to60[4]); h16aa_55to60[0]->Add(h16aa_55to60[5]);
    cout << "h16aa_55to60[0] = " << h16aa_55to60[0]->GetEntries() << endl;
    h16aa_55to60[0]->Scale(factor/h16aa_55to60[0]->GetEntries());
    
    
    h17aa_5to10[0]->Add(h17aa_5to10[1]);h17aa_5to10[0]->Add(h17aa_5to10[2]);h17aa_5to10[0]->Add(h17aa_5to10[3]); h17aa_5to10[0]->Add(h17aa_5to10[4]); h17aa_5to10[0]->Add(h17aa_5to10[5]);
    cout << "h17aa_5to10[0] = " << h17aa_5to10[0]->GetEntries() << endl;
    h17aa_5to10[0]->Scale(factor/h17aa_5to10[0]->GetEntries());
    
    h17aa_10to15[0]->Add(h17aa_10to15[1]);h17aa_10to15[0]->Add(h17aa_10to15[2]);h17aa_10to15[0]->Add(h17aa_10to15[3]); h17aa_10to15[0]->Add(h17aa_10to15[4]); h17aa_10to15[0]->Add(h17aa_10to15[5]);
    cout << "h17aa_10to15[0] = " << h17aa_10to15[0]->GetEntries() << endl;
    h17aa_10to15[0]->Scale(factor/h17aa_10to15[0]->GetEntries());
    
    h17aa_15to20[0]->Add(h17aa_15to20[1]);h17aa_15to20[0]->Add(h17aa_15to20[2]);h17aa_15to20[0]->Add(h17aa_15to20[3]); h17aa_15to20[0]->Add(h17aa_15to20[4]); h17aa_15to20[0]->Add(h17aa_15to20[5]);
    cout << "h17aa_15to20[0] = " << h17aa_15to20[0]->GetEntries() << endl;
    h17aa_15to20[0]->Scale(factor/h17aa_15to20[0]->GetEntries());
    
    h17aa_20to25[0]->Add(h17aa_20to25[1]);h17aa_20to25[0]->Add(h17aa_20to25[2]);h17aa_20to25[0]->Add(h17aa_20to25[3]); h17aa_20to25[0]->Add(h17aa_20to25[4]); h17aa_20to25[0]->Add(h17aa_20to25[5]);
    cout << "h17aa_20to25[0] = " << h17aa_20to25[0]->GetEntries() << endl;
    h17aa_20to25[0]->Scale(factor/h17aa_20to25[0]->GetEntries());
    
    h17aa_25to30[0]->Add(h17aa_25to30[1]);h17aa_25to30[0]->Add(h17aa_25to30[2]);h17aa_25to30[0]->Add(h17aa_25to30[3]); h17aa_25to30[0]->Add(h17aa_25to30[4]); h17aa_25to30[0]->Add(h17aa_25to30[5]);
    cout << "h17aa_25to30[0] = " << h17aa_25to30[0]->GetEntries() << endl;
    h17aa_25to30[0]->Scale(factor/h17aa_25to30[0]->GetEntries());
    
    h17aa_30to35[0]->Add(h17aa_30to35[1]);h17aa_30to35[0]->Add(h17aa_30to35[2]);h17aa_30to35[0]->Add(h17aa_30to35[3]); h17aa_30to35[0]->Add(h17aa_30to35[4]); h17aa_30to35[0]->Add(h17aa_30to35[5]);
    cout << "h17aa_30to35[0] = " << h17aa_30to35[0]->GetEntries() << endl;
    h17aa_30to35[0]->Scale(factor/h17aa_30to35[0]->GetEntries());
    
    h17aa_35to40[0]->Add(h17aa_35to40[1]);h17aa_35to40[0]->Add(h17aa_35to40[2]);h17aa_35to40[0]->Add(h17aa_35to40[3]); h17aa_35to40[0]->Add(h17aa_35to40[4]); h17aa_35to40[0]->Add(h17aa_35to40[5]);
    cout << " h17aa_35to40[0] = " <<  h17aa_35to40[0]->GetEntries() << endl;
    h17aa_35to40[0]->Scale(factor/h17aa_35to40[0]->GetEntries());
    
    h17aa_40to45[0]->Add(h17aa_40to45[1]);h17aa_40to45[0]->Add(h17aa_40to45[2]);h17aa_40to45[0]->Add(h17aa_40to45[3]); h17aa_40to45[0]->Add(h17aa_40to45[4]); h17aa_40to45[0]->Add(h17aa_40to45[5]);
    cout << "h17aa_40to45[0] = " << h17aa_40to45[0]->GetEntries() << endl;
    h17aa_40to45[0]->Scale(factor/h17aa_40to45[0]->GetEntries());
    
    h17aa_45to50[0]->Add(h17aa_45to50[1]);h17aa_45to50[0]->Add(h17aa_45to50[2]);h17aa_45to50[0]->Add(h17aa_45to50[3]); h17aa_45to50[0]->Add(h17aa_45to50[4]); h17aa_45to50[0]->Add(h17aa_45to50[5]);
    cout << "h17aa_45to50[0] = " << h17aa_45to50[0]->GetEntries() << endl;
    h17aa_45to50[0]->Scale(factor/h17aa_45to50[0]->GetEntries());
    
    h17aa_50to55[0]->Add(h17aa_50to55[1]);h17aa_50to55[0]->Add(h17aa_50to55[2]);h17aa_50to55[0]->Add(h17aa_50to55[3]); h17aa_50to55[0]->Add(h17aa_50to55[4]); h17aa_50to55[0]->Add(h17aa_50to55[5]);
    cout << "h17aa_50to55[0] = " << h17aa_50to55[0]->GetEntries() << endl;
    h17aa_50to55[0]->Scale(factor/h17aa_50to55[0]->GetEntries());
    
    h17aa_55to60[0]->Add(h17aa_55to60[1]);h17aa_55to60[0]->Add(h17aa_55to60[2]);h17aa_55to60[0]->Add(h17aa_55to60[3]); h17aa_55to60[0]->Add(h17aa_55to60[4]); h17aa_55to60[0]->Add(h17aa_55to60[5]);
    cout << "h17aa_55to60[0] = " << h17aa_55to60[0]->GetEntries() << endl;
    h17aa_55to60[0]->Scale(factor/h17aa_55to60[0]->GetEntries());
    
    h10aa[0]->Add(h10aa[1]);h10aa[0]->Add(h10aa[2]);h10aa[0]->Add(h10aa[3]); h10aa[0]->Add(h10aa[4]); h10aa[0]->Add(h10aa[5]);
    cout << " h10aa[0]= " << h10aa[0]->GetEntries() << endl;
    h10aa[0]->Scale(factor/h10aa[0]->GetEntries());
   // h7aa[0]->Add(h7aa[1]);h7aa[0]->Add(h7aa[2]);h7aa[0]->Add(h7aa[3]); h7aa[0]->Add(h7aa[4]); h7aa[0]->Add(h7aa[5]);
 //   h7aa[0]->Scale(factor/h7aa[0]->GetEntries());
    h11aa[0]->Add(h11aa[1]);h11aa[0]->Add(h11aa[2]);h11aa[0]->Add(h11aa[3]); h11aa[0]->Add(h11aa[4]); h11aa[0]->Add(h11aa[5]);
    cout << "h11aa = " << h11aa[0]->GetEntries() << endl;
    h11aa[0]->Scale(factor/h11aa[0]->GetEntries());
   // h8aa[0]->Add(h8aa[1]);h8aa[0]->Add(h8aa[2]);h8aa[0]->Add(h8aa[3]); h8aa[0]->Add(h8aa[4]); h8aa[0]->Add(h8aa[5]);
  //  h8aa[0]->Scale(factor/h8aa[0]->GetEntries());
    
    
    h6aa_5to10[0]->SetLineColor(kGreen);
    h6aa_10to15[0]->SetLineColor(kGreen);
    h6aa_15to20[0]->SetLineColor(kGreen);
    h6aa_20to25[0]->SetLineColor(kGreen);
    h6aa_25to30[0]->SetLineColor(kGreen);
    h6aa_30to35[0]->SetLineColor(kGreen);
    h6aa_35to40[0]->SetLineColor(kGreen);
    h6aa_40to45[0]->SetLineColor(kGreen);
    h6aa_45to50[0]->SetLineColor(kGreen);
    h6aa_50to55[0]->SetLineColor(kGreen);
    h6aa_55to60[0]->SetLineColor(kGreen);
    
    
    h7aa_5to10[0]->SetLineColor(kGreen);
    h7aa_10to15[0]->SetLineColor(kGreen);
    h7aa_15to20[0]->SetLineColor(kGreen);
    h7aa_20to25[0]->SetLineColor(kGreen);
    h7aa_25to30[0]->SetLineColor(kGreen);
    h7aa_30to35[0]->SetLineColor(kGreen);
    h7aa_35to40[0]->SetLineColor(kGreen);
    h7aa_40to45[0]->SetLineColor(kGreen);
    h7aa_45to50[0]->SetLineColor(kGreen);
    h7aa_50to55[0]->SetLineColor(kGreen);
    h7aa_55to60[0]->SetLineColor(kGreen);
    
    h8aa_5to10[0]->SetLineColor(kGreen);
    h8aa_10to15[0]->SetLineColor(kGreen);
    h8aa_15to20[0]->SetLineColor(kGreen);
    h8aa_20to25[0]->SetLineColor(kGreen);
    h8aa_25to30[0]->SetLineColor(kGreen);
    h8aa_30to35[0]->SetLineColor(kGreen);
    h8aa_35to40[0]->SetLineColor(kGreen);
    h8aa_40to45[0]->SetLineColor(kGreen);
    h8aa_45to50[0]->SetLineColor(kGreen);
    h8aa_50to55[0]->SetLineColor(kGreen);
    h8aa_55to60[0]->SetLineColor(kGreen);
    
    h12aa_5to10[0]->SetLineColor(kGreen);
    h12aa_10to15[0]->SetLineColor(kGreen);
    h12aa_15to20[0]->SetLineColor(kGreen);
    h12aa_20to25[0]->SetLineColor(kGreen);
    h12aa_25to30[0]->SetLineColor(kGreen);
    h12aa_30to35[0]->SetLineColor(kGreen);
    h12aa_35to40[0]->SetLineColor(kGreen);
    h12aa_40to45[0]->SetLineColor(kGreen);
    h12aa_45to50[0]->SetLineColor(kGreen);
    h12aa_50to55[0]->SetLineColor(kGreen);
    h12aa_55to60[0]->SetLineColor(kGreen);
    
    h13aa_5to10[0]->SetLineColor(kGreen);
    h13aa_10to15[0]->SetLineColor(kGreen);
    h13aa_15to20[0]->SetLineColor(kGreen);
    h13aa_20to25[0]->SetLineColor(kGreen);
    h13aa_25to30[0]->SetLineColor(kGreen);
    h13aa_30to35[0]->SetLineColor(kGreen);
    h13aa_35to40[0]->SetLineColor(kGreen);
    h13aa_40to45[0]->SetLineColor(kGreen);
    h13aa_45to50[0]->SetLineColor(kGreen);
    h13aa_50to55[0]->SetLineColor(kGreen);
    h13aa_55to60[0]->SetLineColor(kGreen);
    
    h14aa_5to10[0]->SetLineColor(kGreen);
    h14aa_10to15[0]->SetLineColor(kGreen);
    h14aa_15to20[0]->SetLineColor(kGreen);
    h14aa_20to25[0]->SetLineColor(kGreen);
    h14aa_25to30[0]->SetLineColor(kGreen);
    h14aa_30to35[0]->SetLineColor(kGreen);
    h14aa_35to40[0]->SetLineColor(kGreen);
    h14aa_40to45[0]->SetLineColor(kGreen);
    h14aa_45to50[0]->SetLineColor(kGreen);
    h14aa_50to55[0]->SetLineColor(kGreen);
    h14aa_55to60[0]->SetLineColor(kGreen);
    
    h15aa_5to10[0]->SetLineColor(kGreen);
    h15aa_10to15[0]->SetLineColor(kGreen);
    h15aa_15to20[0]->SetLineColor(kGreen);
    h15aa_20to25[0]->SetLineColor(kGreen);
    h15aa_25to30[0]->SetLineColor(kGreen);
    h15aa_30to35[0]->SetLineColor(kGreen);
    h15aa_35to40[0]->SetLineColor(kGreen);
    h15aa_40to45[0]->SetLineColor(kGreen);
    h15aa_45to50[0]->SetLineColor(kGreen);
    h15aa_50to55[0]->SetLineColor(kGreen);
    h15aa_55to60[0]->SetLineColor(kGreen);
    
    h16aa_5to10[0]->SetLineColor(kGreen);
    h16aa_10to15[0]->SetLineColor(kGreen);
    h16aa_15to20[0]->SetLineColor(kGreen);
    h16aa_20to25[0]->SetLineColor(kGreen);
    h16aa_25to30[0]->SetLineColor(kGreen);
    h16aa_30to35[0]->SetLineColor(kGreen);
    h16aa_35to40[0]->SetLineColor(kGreen);
    h16aa_40to45[0]->SetLineColor(kGreen);
    h16aa_45to50[0]->SetLineColor(kGreen);
    h16aa_50to55[0]->SetLineColor(kGreen);
    h16aa_55to60[0]->SetLineColor(kGreen);
    
    h17aa_5to10[0]->SetLineColor(kGreen);
    h17aa_10to15[0]->SetLineColor(kGreen);
    h17aa_15to20[0]->SetLineColor(kGreen);
    h17aa_20to25[0]->SetLineColor(kGreen);
    h17aa_25to30[0]->SetLineColor(kGreen);
    h17aa_30to35[0]->SetLineColor(kGreen);
    h17aa_35to40[0]->SetLineColor(kGreen);
    h17aa_40to45[0]->SetLineColor(kGreen);
    h17aa_45to50[0]->SetLineColor(kGreen);
    h17aa_50to55[0]->SetLineColor(kGreen);
    h17aa_55to60[0]->SetLineColor(kGreen);
    

 //   h7aa[0]->SetLineColor(kGreen);
//    h8aa[0]->SetLineColor(kGreen);
    h9aa[0]->SetLineColor(kGreen);
    h10aa[0]->SetLineColor(kGreen);
    h11aa[0]->SetLineColor(kGreen);
    
    
    
     TCanvas *c4 = new TCanvas("c4");
     c4->Divide(3,3);
c4->cd(1);gPad->SetLogy();h9->Draw("SURF3");
 c4->cd(2);gPad->SetLogy();h9b->Draw("SURF3");
    c4->cd(3);gPad->SetLogy();h9aa[0]->Draw("SURF3");
 //   c4->cd(4);gPad->SetLogy(); h6->Draw(); h6b->Draw("same");h6aa[0]->Draw("same");
//    TLegend *legend6 = new TLegend(0.67,0.7,0.89,0.88);
//    legend6->AddEntry(h6,"rec","l");
//    legend6->AddEntry(h6b,"gen","l");
//    legend6->AddEntry(h6aa[0],"data","l");
//      legend6->Draw();
c4->cd(4);gPad->SetLogy();h10->Draw("SURF3");
c4->cd(5);gPad->SetLogy();h10b->Draw("SURF3");
    c4->cd(6);gPad->SetLogy();h10aa[0]->Draw("SURF3");
//    c4->cd(8);gPad->SetLogy(); h7->Draw(); h7b->Draw("same");h7aa[0]->Draw("same");
//    TLegend *legend7 = new TLegend(0.67,0.7,0.89,0.88);
//    legend7->AddEntry(h7,"rec","l");
//    legend7->AddEntry(h7b,"gen","l");
//      legend7->Draw();
 c4->cd(7);gPad->SetLogy();h11->Draw("SURF3");
 c4->cd(8);gPad->SetLogy();h11b->Draw("SURF3");
    c4->cd(9);gPad->SetLogy();h11aa[0]->Draw("SURF3");
//    c4->cd(12);gPad->SetLogy(); h8->Draw(); h8b->Draw("same");h8aa[0]->Draw("same");
//    TLegend *legend8 = new TLegend(0.67,0.7,0.89,0.88);
 //   legend8->AddEntry(h8,"rec","l");
 //   legend8->AddEntry(h8b,"gen","l");
 //     legend8->Draw();


 TCanvas *c4b = new TCanvas("c4b");
     c4b->Divide(2,2);
    ratiop(c4b, 1, h6_5to10,  h6b_5to10,  h6aa_5to10[0]);
    ratiop(c4b, 2, h6_10to15, h6b_10to15, h6aa_10to15[0]);
    ratiop(c4b, 3, h6_15to20, h6b_15to20, h6aa_15to20[0]);
    ratiop(c4b, 4, h6_20to25, h6b_20to25, h6aa_20to25[0]);
    
    TCanvas *c4c = new TCanvas("c4c");
        c4c->Divide(2,2);
    ratiop(c4c, 1, h6_25to30, h6b_25to30, h6aa_25to30[0]);
    ratiop(c4c, 2, h6_30to35, h6b_30to35, h6aa_30to35[0]);
    ratiop(c4c, 3, h6_35to40, h6b_35to40, h6aa_35to40[0]);
    ratiop(c4c, 4, h6_40to45, h6b_40to45, h6aa_40to45[0]);
    
    TCanvas *c4d = new TCanvas("c4d");
        c4d->Divide(2,2);
    ratiop(c4d, 1, h6_45to50, h6b_45to50, h6aa_45to50[0]);
    ratiop(c4d, 2, h6_50to55, h6b_50to55, h6aa_50to55[0]);
    ratiop(c4d, 3, h6_55to60, h6b_55to60, h6aa_55to60[0]);
    
    
    TCanvas *c4e = new TCanvas("c4e");
        c4e->Divide(2,2);
    ratiop(c4e, 1, h7_5to10, h7b_5to10, h7aa_5to10[0]);
    ratiop(c4e, 2, h7_10to15, h7b_10to15, h7aa_10to15[0]);
    ratiop(c4e, 3, h7_15to20, h7b_15to20, h7aa_15to20[0]);
    ratiop(c4e, 4, h7_20to25, h7b_20to25, h7aa_20to25[0]);
    
    TCanvas *c4f = new TCanvas("c4f");
        c4f->Divide(2,2);
    ratiop(c4f, 1, h7_25to30, h7b_25to30, h7aa_25to30[0]);
    ratiop(c4f, 2, h7_30to35, h7b_30to35, h7aa_30to35[0]);
    ratiop(c4f, 3, h7_35to40, h7b_35to40, h7aa_35to40[0]);
    ratiop(c4f, 4, h7_40to45, h7b_40to45, h7aa_40to45[0]);
      
    TCanvas *c4g = new TCanvas("c4g");
        c4g->Divide(2,2);
    ratiop(c4g, 1, h7_45to50, h7b_45to50, h7aa_45to50[0]);
    ratiop(c4g, 2, h7_50to55, h7b_50to55, h7aa_50to55[0]);
    ratiop(c4g, 3, h7_55to60, h7b_55to60, h7aa_55to60[0]);
    
    TCanvas *c4h = new TCanvas("c4h");
        c4h->Divide(2,2);
    ratiop(c4h, 1, h8_5to10, h8b_5to10, h8aa_5to10[0]);
    ratiop(c4h, 2, h8_10to15, h8b_10to15, h8aa_10to15[0]);
    ratiop(c4h, 3, h8_15to20, h8b_15to20, h8aa_15to20[0]);
    ratiop(c4h, 4, h8_20to25, h8b_20to25, h8aa_20to25[0]);
    
    TCanvas *c4i = new TCanvas("c4i");
        c4i->Divide(2,2);
    ratiop(c4i, 1, h8_25to30, h8b_25to30, h8aa_25to30[0]);
    ratiop(c4i, 2, h8_30to35, h8b_30to35, h8aa_30to35[0]);
    ratiop(c4i, 3, h8_35to40, h8b_35to40, h8aa_35to40[0]);
    ratiop(c4i, 4, h8_40to45, h8b_40to45, h8aa_40to45[0]);
    
    TCanvas *c4j= new TCanvas("c4j");
        c4j->Divide(2,2);
    ratiop(c4j, 1, h8_45to50, h8b_45to50, h8aa_45to50[0]);
    ratiop(c4j, 2, h8_50to55, h8b_50to55, h8aa_50to55[0]);
    ratiop(c4j, 3, h8_55to60, h8b_55to60, h8aa_55to60[0]);

    
//    h12aa[0]->Add(h12aa[1]);h12aa[0]->Add(h12aa[2]);h12aa[0]->Add(h12aa[3]); h12aa[0]->Add(h12aa[4]); h12aa[0]->Add(h12aa[5]);
 //   h12aa[0]->Scale(factor/h12aa[0]->GetEntries());
//    h13aa[0]->Add(h13aa[1]);h13aa[0]->Add(h13aa[2]);h13aa[0]->Add(h13aa[3]); h13aa[0]->Add(h13aa[4]); h13aa[0]->Add(h13aa[5]);
//    h13aa[0]->Scale(factor/h13aa[0]->GetEntries());
//    h14aa[0]->Add(h14aa[1]);h14aa[0]->Add(h14aa[2]);h14aa[0]->Add(h14aa[3]); h14aa[0]->Add(h14aa[4]); h14aa[0]->Add(h14aa[5]);
//    h14aa[0]->Scale(factor/h14aa[0]->GetEntries());
//    h15aa[0]->Add(h15aa[1]);h15aa[0]->Add(h15aa[2]);h15aa[0]->Add(h15aa[3]); h15aa[0]->Add(h15aa[4]); h15aa[0]->Add(h15aa[5]);
//    h15aa[0]->Scale(factor/h15aa[0]->GetEntries());
//    h16aa[0]->Add(h16aa[1]);h16aa[0]->Add(h16aa[2]);h16aa[0]->Add(h16aa[3]); h16aa[0]->Add(h16aa[4]); h16aa[0]->Add(h16aa[5]);
//    h16aa[0]->Scale(factor/h16aa[0]->GetEntries());
//    h17aa[0]->Add(h17aa[1]);h17aa[0]->Add(h17aa[2]);h17aa[0]->Add(h17aa[3]); h17aa[0]->Add(h17aa[4]); h17aa[0]->Add(h17aa[5]);
//    h17aa[0]->Scale(factor/h17aa[0]->GetEntries());
    
//   h12aa[0]->SetLineColor(kGreen);
 //   h13aa[0]->SetLineColor(kGreen);
 //   h14aa[0]->SetLineColor(kGreen);
 //   h15aa[0]->SetLineColor(kGreen);
 //   h16aa[0]->SetLineColor(kGreen);
 //   h17aa[0]->SetLineColor(kGreen);
    
    
 TCanvas *c5 = new TCanvas("c5");
       c5->Divide(2,2);
    ratiop(c5, 1, h12_5to10, h12b_5to10, h12aa_5to10[0]);
    ratiop(c5, 2, h12_10to15, h12b_10to15, h12aa_10to15[0]);
    ratiop(c5, 3, h12_15to20, h12b_15to20, h12aa_15to20[0]);
    ratiop(c5, 4, h12_20to25, h12b_20to25, h12aa_20to25[0]);
    
    TCanvas *c5b = new TCanvas("c5b");
          c5b->Divide(2,2);
    ratiop(c5b, 1, h12_25to30, h12b_25to30, h12aa_25to30[0]);
    ratiop(c5b, 2, h12_30to35, h12b_30to35, h12aa_30to35[0]);
    ratiop(c5b, 3, h12_35to40, h12b_35to40, h12aa_35to40[0]);
    ratiop(c5b, 4, h12_40to45, h12b_40to45, h12aa_40to45[0]);
    
    TCanvas *c5c = new TCanvas("c5c");
          c5c->Divide(2,2);
    ratiop(c5c, 1, h12_45to50, h12b_45to50, h12aa_45to50[0]);
    ratiop(c5c, 2, h12_50to55, h12b_50to55, h12aa_50to55[0]);
    ratiop(c5c, 3, h12_55to60, h12b_55to60, h12aa_55to60[0]);

    TCanvas *c6 = new TCanvas("c6");
        c6->Divide(2,2);
    ratiop(c6, 1, h13_5to10, h13b_5to10, h13aa_5to10[0]);
    ratiop(c6, 2, h13_10to15, h13b_10to15, h13aa_10to15[0]);
    ratiop(c6, 3, h13_15to20, h13b_15to20, h13aa_15to20[0]);
    ratiop(c6, 4, h13_20to25, h13b_20to25, h13aa_20to25[0]);
    
    TCanvas *c6b = new TCanvas("c6b");
          c6b->Divide(2,2);
    ratiop(c6b, 1, h13_25to30, h13b_25to30, h13aa_25to30[0]);
    ratiop(c6b, 2, h13_30to35, h13b_30to35, h13aa_30to35[0]);
    ratiop(c6b, 3, h13_35to40, h13b_35to40, h13aa_35to40[0]);
    ratiop(c6b, 4, h13_40to45, h13b_40to45, h13aa_40to45[0]);
    
    TCanvas *c6c = new TCanvas("c6c");
          c6c->Divide(2,2);
    ratiop(c6c, 1, h13_45to50, h13b_45to50, h13aa_45to50[0]);
    ratiop(c6c, 2, h13_50to55, h13b_50to55, h13aa_50to55[0]);
    ratiop(c6c, 3, h13_55to60, h13b_55to60, h13aa_55to60[0]);

    
    TCanvas *c7 = new TCanvas("c7");
          c7->Divide(2,2);
    ratiop(c7, 1, h14_5to10, h14b_5to10, h14aa_5to10[0]);
    ratiop(c7, 2, h14_10to15, h14b_10to15, h14aa_10to15[0]);
    ratiop(c7, 3, h14_15to20, h14b_15to20, h14aa_15to20[0]);
    ratiop(c7, 4, h14_20to25, h14b_20to25, h14aa_20to25[0]);
    
    TCanvas *c7b = new TCanvas("c7b");
          c7b->Divide(2,2);
    ratiop(c7b, 1, h14_25to30, h14b_25to30, h14aa_25to30[0]);
    ratiop(c7b, 2, h14_30to35, h14b_30to35, h14aa_30to35[0]);
    ratiop(c7b, 3, h14_35to40, h14b_35to40, h14aa_35to40[0]);
    ratiop(c7b, 4, h14_40to45, h14b_40to45, h14aa_40to45[0]);
    
    TCanvas *c7c = new TCanvas("c7c");
          c7c->Divide(2,2);
    ratiop(c7c, 1, h14_45to50, h14b_45to50, h14aa_45to50[0]);
    ratiop(c7c, 2, h14_50to55, h14b_50to55, h14aa_50to55[0]);
    ratiop(c7c, 3, h14_55to60, h14b_55to60, h14aa_55to60[0]);
    
    
    TCanvas *c8 = new TCanvas("c8");
          c8->Divide(2,2);
    ratiop(c8, 1, h15_5to10, h15b_5to10, h15aa_5to10[0]);
    ratiop(c8, 2, h15_10to15, h15b_10to15, h15aa_10to15[0]);
    ratiop(c8, 3, h15_15to20, h15b_15to20, h15aa_15to20[0]);
    ratiop(c8, 4, h15_20to25, h15b_20to25, h15aa_20to25[0]);
    
    TCanvas *c8b = new TCanvas("c8b");
          c8b->Divide(2,2);
    ratiop(c8b, 1, h15_25to30, h15b_25to30, h15aa_25to30[0]);
    ratiop(c8b, 2, h15_30to35, h15b_30to35, h15aa_30to35[0]);
    ratiop(c8b, 3, h15_35to40, h15b_35to40, h15aa_35to40[0]);
    ratiop(c8b, 4, h15_40to45, h15b_40to45, h15aa_40to45[0]);
    
    TCanvas *c8c = new TCanvas("c8c");
          c8c->Divide(2,2);
    ratiop(c8c, 1, h15_45to50, h15b_45to50, h15aa_45to50[0]);
    ratiop(c8c, 2, h15_50to55, h15b_50to55, h15aa_50to55[0]);
    ratiop(c8c, 3, h15_55to60, h15b_55to60, h15aa_55to60[0]);
    
    TCanvas *c9 = new TCanvas("c9");
          c9->Divide(2,2);
    ratiop(c9, 1, h16_5to10, h16b_5to10, h16aa_5to10[0]);
    ratiop(c9, 2, h16_10to15, h16b_10to15, h16aa_10to15[0]);
    ratiop(c9, 3, h16_15to20, h16b_15to20, h16aa_15to20[0]);
    ratiop(c9, 4, h16_20to25, h16b_20to25, h16aa_20to25[0]);
    
    TCanvas *c9b = new TCanvas("c9b");
          c9b->Divide(2,2);
    ratiop(c9b, 1, h16_25to30, h16b_25to30, h16aa_25to30[0]);
    ratiop(c9b, 2, h16_30to35, h16b_30to35, h16aa_30to35[0]);
    ratiop(c9b, 3, h16_35to40, h16b_35to40, h16aa_35to40[0]);
    ratiop(c9b, 4, h16_40to45, h16b_40to45, h16aa_40to45[0]);
    
    TCanvas *c9c = new TCanvas("c9c");
          c9c->Divide(2,2);
    ratiop(c9c, 1, h16_45to50, h16b_45to50, h16aa_45to50[0]);
    ratiop(c9c, 2, h16_50to55, h16b_50to55, h16aa_50to55[0]);
    ratiop(c9c, 3, h16_55to60, h16b_55to60, h16aa_55to60[0]);
    
    TCanvas *c10 = new TCanvas("c10");
          c10->Divide(2,2);
    ratiop(c10, 1, h17_5to10, h17b_5to10, h17aa_5to10[0]);
    ratiop(c10, 2, h17_10to15, h17b_10to15, h17aa_10to15[0]);
    ratiop(c10, 3, h17_15to20, h17b_15to20, h17aa_15to20[0]);
    ratiop(c10, 4, h17_20to25, h17b_20to25, h17aa_20to25[0]);
    
    TCanvas *c10b = new TCanvas("c10b");
          c10b->Divide(2,2);
    ratiop(c10b, 1, h17_25to30, h17b_25to30, h17aa_25to30[0]);
    ratiop(c10b, 2, h17_30to35, h17b_30to35, h17aa_30to35[0]);
    ratiop(c10b, 3, h17_35to40, h17b_35to40, h17aa_35to40[0]);
    ratiop(c10b, 4, h17_40to45, h17b_40to45, h17aa_40to45[0]);
    
    TCanvas *c10c = new TCanvas("c10c");
          c10c->Divide(2,2);
    ratiop(c10c, 1, h17_45to50, h17b_45to50, h17aa_45to50[0]);
    ratiop(c10c, 2, h17_50to55, h17b_50to55, h17aa_50to55[0]);
    ratiop(c10c, 3, h17_55to60, h17b_55to60, h17aa_55to60[0]);

    TCanvas *c1z = new TCanvas("c1z");
    c1z->Divide(4,3);
    c1z->cd(1); h1z_5to10->Draw("colz"); c1z->cd(2); h1z_10to15->Draw("colz"); c1z->cd(3); h1z_15to20->Draw("colz"); c1z->cd(4); h1z_20to25->Draw("colz");
    c1z->cd(5); h1z_25to30->Draw("colz"); c1z->cd(6); h1z_30to35->Draw("colz"); c1z->cd(7); h1z_35to40->Draw("colz"); c1z->cd(8); h1z_40to45->Draw("colz");
    c1z->cd(9); h1z_45to50->Draw("colz"); c1z->cd(10); h1z_50to55->Draw("colz"); c1z->cd(11); h1z_55to60->Draw("colz");
    
    TCanvas *c1zg = new TCanvas("c1zg");
    c1zg->Divide(4,3);
    c1zg->cd(1); h1zg_5to10->Draw("colz"); c1zg->cd(2); h1zg_10to15->Draw("colz"); c1zg->cd(3); h1zg_15to20->Draw("colz"); c1zg->cd(4); h1zg_20to25->Draw("colz");
    c1zg->cd(5); h1zg_25to30->Draw("colz"); c1zg->cd(6); h1zg_30to35->Draw("colz"); c1zg->cd(7); h1zg_35to40->Draw("colz"); c1zg->cd(8); h1zg_40to45->Draw("colz");
    c1zg->cd(9); h1zg_45to50->Draw("colz"); c1zg->cd(10); h1zg_50to55->Draw("colz"); c1zg->cd(11); h1zg_55to60->Draw("colz");
    
    TCanvas *c1zw = new TCanvas("c1zw");
    c1zw->Divide(4,3);
    c1zw->cd(1); h1zw_5to10->Draw("colz"); c1zw->cd(2); h1zw_10to15->Draw("colz"); c1zw->cd(3); h1zw_15to20->Draw("colz"); c1zw->cd(4); h1zw_20to25->Draw("colz");
    c1zw->cd(5); h1zw_25to30->Draw("colz"); c1zw->cd(6); h1zw_30to35->Draw("colz"); c1zw->cd(7); h1zw_35to40->Draw("colz"); c1zw->cd(8); h1zw_40to45->Draw("colz");
    c1zw->cd(9); h1zw_45to50->Draw("colz"); c1zw->cd(10); h1zw_50to55->Draw("colz"); c1zw->cd(11); h1zw_55to60->Draw("colz");
    
    
    TCanvas *c2z = new TCanvas("c2z");
    c2z->Divide(4,3);
    c2z->cd(1); h2z_5to10->Draw(); c2z->cd(2); h2z_10to15->Draw(); c2z->cd(3); h2z_15to20->Draw(); c2z->cd(4); h2z_20to25->Draw();
    c2z->cd(5); h2z_25to30->Draw(); c2z->cd(6); h2z_30to35->Draw(); c2z->cd(7); h2z_35to40->Draw(); c2z->cd(8); h2z_40to45->Draw();
    c2z->cd(9); h2z_45to50->Draw(); c2z->cd(10); h2z_50to55->Draw(); c2z->cd(11); h2z_55to60->Draw();
    
    TCanvas *c2zw = new TCanvas("c2zw");
    c2zw->Divide(4,3);
    c2zw->cd(1); h2zw_5to10->Draw(); c2zw->cd(2); h2zw_10to15->Draw(); c2zw->cd(3); h2zw_15to20->Draw(); c2zw->cd(4); h2zw_20to25->Draw();
    c2zw->cd(5); h2zw_25to30->Draw(); c2zw->cd(6); h2zw_30to35->Draw(); c2zw->cd(7); h2zw_35to40->Draw(); c2zw->cd(8); h2zw_40to45->Draw();
    c2zw->cd(9); h2zw_45to50->Draw(); c2zw->cd(10); h2zw_50to55->Draw(); c2zw->cd(11); h2zw_55to60->Draw();
    
    TCanvas *c2zg = new TCanvas("c2zg");
    c2zg->Divide(4,3);
    c2zg->cd(1); h2zg_5to10->Draw(); c2zg->cd(2); h2zg_10to15->Draw(); c2zg->cd(3); h2zg_15to20->Draw(); c2zg->cd(4); h2zg_20to25->Draw();
    c2zg->cd(5); h2zg_25to30->Draw(); c2zg->cd(6); h2zg_30to35->Draw(); c2zg->cd(7); h2zg_35to40->Draw(); c2zg->cd(8); h2zg_40to45->Draw();
    c2zg->cd(9); h2zg_45to50->Draw(); c2zg->cd(10); h2zg_50to55->Draw(); c2zg->cd(11); h2zg_55to60->Draw();
    
    
    TCanvas *c3z = new TCanvas("c3z");
    c3z->Divide(4,3);
    c3z->cd(1); h3z_5to10->Draw(); c3z->cd(2); h3z_10to15->Draw(); c3z->cd(3); h3z_15to20->Draw(); c3z->cd(4); h3z_20to25->Draw();
    c3z->cd(5); h3z_25to30->Draw(); c3z->cd(6); h3z_30to35->Draw(); c3z->cd(7); h3z_35to40->Draw(); c3z->cd(8); h3z_40to45->Draw();
    c3z->cd(9); h3z_45to50->Draw(); c3z->cd(10); h3z_50to55->Draw(); c3z->cd(11); h3z_55to60->Draw();
    
    TCanvas *c3zg = new TCanvas("c3zg");
    c3zg->Divide(4,3);
    c3zg->cd(1); h3zg_5to10->Draw(); c3zg->cd(2); h3zg_10to15->Draw(); c3zg->cd(3); h3zg_15to20->Draw(); c3zg->cd(4); h3zg_20to25->Draw();
    c3zg->cd(5); h3zg_25to30->Draw(); c3zg->cd(6); h3zg_30to35->Draw(); c3zg->cd(7); h3zg_35to40->Draw(); c3zg->cd(8); h3zg_40to45->Draw();
    c3zg->cd(9); h3zg_45to50->Draw(); c3zg->cd(10); h3zg_50to55->Draw(); c3zg->cd(11); h3zg_55to60->Draw();
    
    TCanvas *c3zw = new TCanvas("c3zw");
    c3zw->Divide(4,3);
    c3zw->cd(1); h3zw_5to10->Draw(); c3zw->cd(2); h3zw_10to15->Draw(); c3zw->cd(3); h3zw_15to20->Draw(); c3zw->cd(4); h3zw_20to25->Draw();
    c3zw->cd(5); h3zw_25to30->Draw(); c3zw->cd(6); h3zw_30to35->Draw(); c3zw->cd(7); h3zw_35to40->Draw(); c3zw->cd(8); h3zw_40to45->Draw();
    c3zw->cd(9); h3zw_45to50->Draw(); c3zw->cd(10); h3zw_50to55->Draw(); c3zw->cd(11); h3zw_55to60->Draw();
    
    TCanvas *cza = new TCanvas("cza");
    cza->Divide(1,3);
    cza->cd(1); hza_rec_gen->Draw("COLZ"); cza->cd(2); hzag_rec_gen->Draw("COLZ"); cza->cd(3); hzaw_rec_gen->Draw("COLZ");
    
    TCanvas *cz1 = new TCanvas("cz1");
    cz1->cd(); hz_rec_gen->Draw("COLZ");
    
    TCanvas *cz2 = new TCanvas("cz2");
    cz2->cd(); hzw_rec_gen->Draw("COLZ");
    
    TCanvas *cz3 = new TCanvas("cz3");
    cz3->cd();hzg_rec_gen->Draw("COLZ");
    
    
    TCanvas *c12 = new TCanvas("c12");
          c12->Divide(4,3);
    c12->cd(1); h12z_5to10->Draw();
    c12->cd(2); h12z_10to15->Draw();
    c12->cd(3); h12z_15to20->Draw();
    c12->cd(4); h12z_20to25->Draw();
    c12->cd(5); h12z_25to30->Draw();
    c12->cd(6); h12z_30to35->Draw();
    c12->cd(7); h12z_35to40->Draw();
    c12->cd(8); h12z_40to45->Draw();
    c12->cd(9); h12z_45to50->Draw();
    c12->cd(10);h12z_50to55->Draw();
    c12->cd(11);h12z_55to60->Draw();
    
    TCanvas *c13 = new TCanvas("c13");
          c13->Divide(4,3);
    c13->cd(1); h13z_5to10->Draw();
    c13->cd(2); h13z_10to15->Draw();
    c13->cd(3); h13z_15to20->Draw();
    c13->cd(4); h13z_20to25->Draw();
    c13->cd(5); h13z_25to30->Draw();
    c13->cd(6); h13z_30to35->Draw();
    c13->cd(7); h13z_35to40->Draw();
    c13->cd(8); h13z_40to45->Draw();
    c13->cd(9); h13z_45to50->Draw();
    c13->cd(10);h13z_50to55->Draw();
    c13->cd(11);h13z_55to60->Draw();
    
    TCanvas *c14 = new TCanvas("c14");
          c14->Divide(4,3);
    c14->cd(1); h14z_5to10->Draw();
    c14->cd(2); h14z_10to15->Draw();
    c14->cd(3); h14z_15to20->Draw();
    c14->cd(4); h14z_20to25->Draw();
    c14->cd(5); h14z_25to30->Draw();
    c14->cd(6); h14z_30to35->Draw();
    c14->cd(7); h14z_35to40->Draw();
    c14->cd(8); h14z_40to45->Draw();
    c14->cd(9); h14z_45to50->Draw();
    c14->cd(10);h14z_50to55->Draw();
    c14->cd(11);h14z_55to60->Draw();
    
    TCanvas *c15 = new TCanvas("c15");
          c15->Divide(4,3);
    c15->cd(1); h15z_5to10->Draw();
    c15->cd(2); h15z_10to15->Draw();
    c15->cd(3); h15z_15to20->Draw();
    c15->cd(4); h15z_20to25->Draw();
    c15->cd(5); h15z_25to30->Draw();
    c15->cd(6); h15z_30to35->Draw();
    c15->cd(7); h15z_35to40->Draw();
    c15->cd(8); h15z_40to45->Draw();
    c15->cd(9); h15z_45to50->Draw();
    c15->cd(10);h15z_50to55->Draw();
    c15->cd(11);h15z_55to60->Draw();
    
    TCanvas *c16 = new TCanvas("c16");
          c16->Divide(4,3);
    c16->cd(1); h16z_5to10->Draw();
    c16->cd(2); h16z_10to15->Draw();
    c16->cd(3); h16z_15to20->Draw();
    c16->cd(4); h16z_20to25->Draw();
    c16->cd(5); h16z_25to30->Draw();
    c16->cd(6); h16z_30to35->Draw();
    c16->cd(7); h16z_35to40->Draw();
    c16->cd(8); h16z_40to45->Draw();
    c16->cd(9); h16z_45to50->Draw();
    c16->cd(10);h16z_50to55->Draw();
    c16->cd(11);h16z_55to60->Draw();
    
    TCanvas *c17 = new TCanvas("c17");
          c17->Divide(4,3);
    c17->cd(1); h17z_5to10->Draw();
    c17->cd(2); h17z_10to15->Draw();
    c17->cd(3); h17z_15to20->Draw();
    c17->cd(4); h17z_20to25->Draw();
    c17->cd(5); h17z_25to30->Draw();
    c17->cd(6); h17z_30to35->Draw();
    c17->cd(7); h17z_35to40->Draw();
    c17->cd(8); h17z_40to45->Draw();
    c17->cd(9); h17z_45to50->Draw();
    c17->cd(10);h17z_50to55->Draw();
    c17->cd(11);h17z_55to60->Draw();
    
    TCanvas *c44 = new TCanvas("c44");
          c44->Divide(4,3);
    c44->cd(1); h6z_5to10->Draw();
    c44->cd(2); h6z_10to15->Draw();
    c44->cd(3); h6z_15to20->Draw();
    c44->cd(4); h6z_20to25->Draw();
    c44->cd(5); h6z_25to30->Draw();
    c44->cd(6); h6z_30to35->Draw();
    c44->cd(7); h6z_35to40->Draw();
    c44->cd(8); h6z_40to45->Draw();
    c44->cd(9); h6z_45to50->Draw();
    c44->cd(10);h6z_50to55->Draw();
    c44->cd(11);h6z_55to60->Draw();
    
    TCanvas *c444 = new TCanvas("c444");
          c444->Divide(4,3);
    c444->cd(1); h7z_5to10->Draw();
    c444->cd(2); h7z_10to15->Draw();
    c444->cd(3); h7z_15to20->Draw();
    c444->cd(4); h7z_20to25->Draw();
    c444->cd(5); h7z_25to30->Draw();
    c444->cd(6); h7z_30to35->Draw();
    c444->cd(7); h7z_35to40->Draw();
    c444->cd(8); h7z_40to45->Draw();
    c444->cd(9); h7z_45to50->Draw();
    c444->cd(10);h7z_50to55->Draw();
    c444->cd(11);h7z_55to60->Draw();
    
    TCanvas *c4444 = new TCanvas("c4444");
          c4444->Divide(4,3);
    c4444->cd(1); h8z_5to10->Draw();
    c4444->cd(2); h8z_10to15->Draw();
    c4444->cd(3); h8z_15to20->Draw();
    c4444->cd(4); h8z_20to25->Draw();
    c4444->cd(5); h8z_25to30->Draw();
    c4444->cd(6); h8z_30to35->Draw();
    c4444->cd(7); h8z_35to40->Draw();
    c4444->cd(8); h8z_40to45->Draw();
    c4444->cd(9); h8z_45to50->Draw();
    c4444->cd(10);h8z_50to55->Draw();
    c4444->cd(11);h8z_55to60->Draw();
    

    
    
    
    
 //       TCanvas *c5b = new TCanvas("c5b");
 //    c5b->Divide(2,3);
 //c5b->cd(1); gPad->SetLogy();h12b->Draw();
 //c5b->cd(2); gPad->SetLogy();h13b->Draw();
 //c5b->cd(3); gPad->SetLogy();h14b->Draw();
 //c5b->cd(4); gPad->SetLogy();h15b->Draw();
 //c5b->cd(5); gPad->SetLogy();h16b->Draw();
 //c5b->cd(6); gPad->SetLogy();h17b->Draw();

    del_pt_E->Scale(factor/del_pt_E->GetEntries());
    del_pt_w->Scale(factor/del_pt_w->GetEntries());
    del_pt_g->Scale(factor/del_pt_g->GetEntries());
    del_eta_E->Scale(factor/del_eta_E->GetEntries());
    del_eta_w->Scale(factor/del_eta_w->GetEntries());
    del_eta_g->Scale(factor/del_eta_g->GetEntries());
    del_phi_E->Scale(factor/del_phi_E->GetEntries());
    del_phi_w->Scale(factor/del_phi_w->GetEntries());
    del_phi_g->Scale(factor/del_phi_g->GetEntries());
    
    
 TCanvas *c2 = new TCanvas("c2");
 c2->Divide(3,1);
    c2->cd(1);gPad->SetLogy();
    del_pt_E->Draw(); del_pt_w->Draw("same"); del_pt_g->Draw("same");
    TLegend *legend4a = new TLegend(0.67,0.7,0.89,0.88);
    legend4a->AddEntry(del_pt_E,"E","l");
    legend4a->AddEntry(del_pt_w,"W","l");
    legend4a->AddEntry(del_pt_g,"g","l");
      legend4a->Draw();
    c2->cd(2);gPad->SetLogy();
    del_eta_E->Draw(); del_eta_w->Draw("same"); del_eta_g->Draw("same");
    TLegend *legend4b = new TLegend(0.67,0.7,0.89,0.88);
    legend4b->AddEntry(del_eta_E,"E","l");
    legend4b->AddEntry(del_eta_w,"W","l");
    legend4b->AddEntry(del_eta_g,"g","l");
      legend4b->Draw();
    c2->cd(3);gPad->SetLogy();
    del_phi_E->Draw(); del_phi_w->Draw("same"); del_phi_g->Draw("same");
    TLegend *legend4c = new TLegend(0.67,0.7,0.89,0.88);
    legend4c->AddEntry(del_phi_E,"E","l");
    legend4c->AddEntry(del_phi_w,"W","l");
    legend4c->AddEntry(del_phi_g,"g","l");
      legend4c->Draw();
// c2->cd(4);gPad->SetLogy();del_pt_w->Draw();
// c2->cd(5);gPad->SetLogy();del_eta_w->Draw();
// c2->cd(6);gPad->SetLogy();del_phi_w->Draw();
 //c2->cd(7);gPad->SetLogy();del_pt_g->Draw();
// c2->cd(8);gPad->SetLogy();del_eta_g->Draw();
// c2->cd(9);gPad->SetLogy();del_phi_g->Draw();

       
 
    
    
    
    //Print plots to file
  //  c1->Print(Form("Lep_%d.pdf[",file_num));
  //  c1->Print(Form("Lep_%d.pdf",file_num));
  //  c3a->Print(Form("Lep_%d.pdf",file_num));
  //   c2->Print(Form("Lep_%d.pdf",file_num));
    c1z->Print(Form("Lep_%d.pdf[",file_num));
    c1z->Print(Form("Lep_%d.pdf",file_num));
    c1zg->Print(Form("Lep_%d.pdf",file_num));
    c1zw->Print(Form("Lep_%d.pdf",file_num));
    c2z->Print(Form("Lep_%d.pdf",file_num));
    c2zg->Print(Form("Lep_%d.pdf",file_num));
    c2zw->Print(Form("Lep_%d.pdf",file_num));
    c3z->Print(Form("Lep_%d.pdf",file_num));
    c3zg->Print(Form("Lep_%d.pdf",file_num));
    c3zw->Print(Form("Lep_%d.pdf",file_num));
    
    cz1->Print(Form("Lep_%d.pdf",file_num));
    cz2->Print(Form("Lep_%d.pdf",file_num));
    cz3->Print(Form("Lep_%d.pdf",file_num));
    cza->Print(Form("Lep_%d.pdf",file_num));
    
     c5->Print(Form("Lep_%d.pdf",file_num));
    c5b->Print(Form("Lep_%d.pdf",file_num));
   // c12->Print(Form("Lep_%d.pdf",file_num));
    c5c->Print(Form("Lep_%d.pdf",file_num));
    c6->Print(Form("Lep_%d.pdf",file_num));
    c6b->Print(Form("Lep_%d.pdf",file_num));
    c6c->Print(Form("Lep_%d.pdf",file_num));
    //c13->Print(Form("Lep_%d.pdf",file_num));
    c7->Print(Form("Lep_%d.pdf",file_num));
    c7b->Print(Form("Lep_%d.pdf",file_num));
    c7c->Print(Form("Lep_%d.pdf",file_num));
    //c14->Print(Form("Lep_%d.pdf",file_num));
    c8->Print(Form("Lep_%d.pdf",file_num));
    c8b->Print(Form("Lep_%d.pdf",file_num));
    c8c->Print(Form("Lep_%d.pdf",file_num));
    //c15->Print(Form("Lep_%d.pdf",file_num));
    c9->Print(Form("Lep_%d.pdf",file_num));
    c9b->Print(Form("Lep_%d.pdf",file_num));
    c9c->Print(Form("Lep_%d.pdf",file_num));
    //c16->Print(Form("Lep_%d.pdf",file_num));
    c10->Print(Form("Lep_%d.pdf",file_num));
    c10b->Print(Form("Lep_%d.pdf",file_num));
    c10c->Print(Form("Lep_%d.pdf",file_num));
    //c17->Print(Form("Lep_%d.pdf",file_num));
    
    c4b->Print(Form("Lep_%d.pdf",file_num));
    c4c->Print(Form("Lep_%d.pdf",file_num));
    c4d->Print(Form("Lep_%d.pdf",file_num));
  //  c44->Print(Form("Lep_%d.pdf",file_num));
    c4e->Print(Form("Lep_%d.pdf",file_num));
    c4f->Print(Form("Lep_%d.pdf",file_num));
    c4g->Print(Form("Lep_%d.pdf",file_num));
   // c444->Print(Form("Lep_%d.pdf",file_num));
    c4h->Print(Form("Lep_%d.pdf",file_num));
    c4i->Print(Form("Lep_%d.pdf",file_num));
    c4j->Print(Form("Lep_%d.pdf",file_num));
    //c4444->Print(Form("Lep_%d.pdf",file_num));
   //  c4->Print(Form("Lep_%d.pdf",file_num));
  //  c2b->Print(Form("Lep_%d.pdf",file_num));
    
    
    
     c2a->Print(Form("Lep_%d.pdf",file_num));
     //  c4b->Print(Form("Lep_%d.pdf",file_num));
    
    c2aa->Print(Form("Lep_%d.pdf",file_num));
    c2aaa->Print(Form("Lep_%d.pdf",file_num));
    c2aaaa->Print(Form("Lep_%d.pdf",file_num));
    c2aaaa->Print(Form("Lep_%d.pdf]",file_num));
    
    

}

