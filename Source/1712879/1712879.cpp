#define _CRT_SECURE_NO_WARNINGS
#include <fcntl.h> 
#include <io.h>
#include <stdio.h>
#include <string.h>
struct SinhVien
{
	wchar_t MSSV[8];
	wchar_t HoTen[30];
	wchar_t email[30];
	wchar_t Khoa[25];
	int KhoaTuyen;
	wchar_t NgaySinh[15];
	wchar_t HinhAnh[15];
	wchar_t MoTa[30];
	wchar_t SoThich[40];
};
int DemSoDong(FILE* fin){
	wchar_t ch; int dong = 1;
	while (1)
	{
		ch = fgetwc(fin);
		if (ch == '\n')
		{
			dong++;
		}
		if (feof(fin))
		{
			break;
		}
			
	}
	return dong;
}
void DocFileCSV(FILE* fin,SinhVien* &sv, int n){
	for (int i = 0; i < n; i++){
		fwscanf(fin, L"%[^,],%[^,],%[^,],%[^,],%ld,%[^,],%[^,],", &sv[i].MSSV, &sv[i].HoTen, &sv[i].email,
			&sv[i].Khoa, &sv[i].KhoaTuyen, &sv[i].NgaySinh, &sv[i].HinhAnh);
		fwscanf(fin, L"%[^,],\"%[^\"]\"\n", &sv[i].MoTa, sv[i].SoThich);
	}
}
wchar_t* NoiChuoi(wchar_t ch[], wchar_t a[]){
	int n1 = wcslen(ch); int n2 = wcslen(a);
	wchar_t* chnew;
	chnew = new wchar_t[n1 + n2];
	wcscpy(chnew, ch);
	wcscat(chnew, a);
	return chnew;
}
void XuatThongTin(SinhVien* sv, int n){
	wprintf(L"Thông Tin Cá Nhân\n");
	for (int i = 0; i < n; i++)
	{
		wprintf(L"%ls\n", sv[i].MSSV);
		wprintf(L"%ls\n", sv[i].HoTen);
		wprintf(L"%ls\n", sv[i].email);
		wprintf(L"%ls\n", sv[i].Khoa);
		wprintf(L"%ld\n", sv[i].KhoaTuyen);
		wprintf(L"%ls\n", sv[i].NgaySinh);
		wprintf(L"%ls\n", sv[i].HinhAnh);
		wprintf(L"%ls\n", sv[i].MoTa);
		wprintf(L"%ls\n", sv[i].SoThich);
		wprintf(L"------------------------\n");
	}
}
void GhiFileHTML(FILE* fout, SinhVien* sv,int i){
	fputws(L"<!DOCTYPE html PUBLIC \"-\//W3C\//DTD XHTML 1.0 Transitional\//EN\" \" http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd \"> \n", fout);
	fputws(L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n", fout);
	fputws(L"	</head>\n", fout);
	fputws(L"\t\t<meta http-equiv=\"Content - Type\" content=\"text / html; charset = utf - 8\" />\n", fout);
	fputws(L"\t\t<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n", fout);
	fwprintf(fout, L"\t\t<title>HCMUS - %ls</title>\n", sv[i].HoTen);
	fputws(L"\t</head>\n", fout);
	fputws(L"\t<body>\n", fout);
	fputws(L"\t\t<div class=\"Layout_container\">\n", fout);
	fputws(L"\t\t\t<!-- Begin Layout Banner Region -->\n", fout);
	fputws(L"\t\t\t<div class=\"Layout_Banner\" >\n", fout);
	fputws(L"\t\t\t\t<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n", fout);
	fputws(L"\t\t\t\t<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n", fout);
	fputws(L"\t\t\t</div>\n", fout);
	fputws(L"\t\t\t<!-- End Layout Banner Region -->\n", fout);
	fputws(L"\t\t\t<!-- Begin Layout MainContents Region -->\n", fout);
	fputws(L"\t\t\t<div class=\"Layout_MainContents\">\n", fout);
	fputws(L"\t\t\t\t<!-- Begin Below Banner Region -->\n", fout);
	fputws(L"\t\t\t\t<div class=\"Personal_Main_Information\">\n", fout);
	fputws(L"\t\t\t\t<!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n", fout);
	fputws(L"\t\t\t\t\t<div class=\"Personal_Location\">\n", fout);
	fputws(L"\t\t\t\t\t\t<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n", fout);
	fwprintf(fout, L"\t\t\t\t\t\t<span class=\"Personal_FullName\">%ls - %ls</span>\n", sv[i].HoTen, sv[i].MSSV);
	fwprintf(fout, L"\t\t\t\t\t\t<div class=\"Personal_Department\">KHOA %ls</div>\n", sv[i].Khoa);
	fputws(L"\t\t\t\t\t\t<br />\n", fout);
	fputws(L"\t\t\t\t\t\t<div class=\"Personal_Phone\">\n", fout);
	fwprintf(fout, L"\t\t\t\t\t\t\tEmail: %ls\n", sv[i].email);
	fputws(L"\t\t\t\t\t\t</div>\n", fout);
	fputws(L"\t\t\t\t\t\t<br />\n", fout);
	fputws(L"\t\t\t\t\t\t<br />\n", fout);
	fputws(L"\t\t\t\t\t</div>\n", fout);
	fputws(L"\t\t\t\t\t<!-- End Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n", fout);
	fputws(L"\t\t\t\t\t<div class=\"Personal_HinhcanhanKhung\">\n", fout);
	fwprintf(fout, L"\t\t\t\t\t\t<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv[i].HinhAnh);
	fputws(L"\t\t\t\t\t</div>\n", fout);
	fputws(L"\t\t\t\t</div>\n", fout);
	fputws(L"\t\t\t\t<!-- End Below Banner Region -->\n", fout);
	fputws(L"\t\t\t\t<!-- Begin MainContents Region -->\n", fout);
	fputws(L"\t\t\t\t<div class=\"MainContain\">\n", fout);
	fputws(L"\t\t\t\t\t\n", fout);
	fputws(L"\t\t\t\t\t<!-- Begin Top Region -->\n", fout);
	fputws(L"\t\t\t\t\t<div class=\"MainContain_Top\">\n", fout);
	fputws(L"\t\t\t\t\t\t\n", fout);
	fputws(L"\t\t\t\t\t<div class=\"InfoGroup\">Thông tin cá nhân</div>\n", fout);
	fputws(L"                        <div>\n",fout);
	fputws(L"                            <ul class=\"TextInList\">\n", fout);
	fwprintf(fout, L"                                <li>Họ và tên: %ls</li>\n", sv[i].HoTen);
	fwprintf(fout, L"\t\t\t\t\t\t\t\t<li>MSSV: %ls</li>\n", sv[i].MSSV);
	fwprintf(fout, L"\t\t\t\t\t\t\t\t<li>Sinh viên khoa : %ls</li>\n", sv[i].Khoa);
	fwprintf(fout, L"\t\t\t\t\t\t\t\t<li>Ngày sinh: %ls</li>\n", sv[i].NgaySinh);
	fwprintf(fout, L"\t\t\t\t\t\t\t\t<li>Email: %ls</li>\n", sv[i].email);
	fputws(L"\t\t\t\t\t\t</ul>\n", fout);
	fputws(L"\t\t\t\t\t</div>\n", fout);
	fputws(L"                        <div class=\"InfoGroup\">Sở thích</div>\n", fout);
	fputws(L"                        <div>\n", fout);
	fputws(L"                            <ul class=\"TextInList\">\n", fout);
	fwprintf(fout, L"                                <li>%ls</li>", sv[i].SoThich);
	fputws(L"\t\t\t\t\t\t</ul>\n", fout);
	fputws(L"\t\t\t\t\t</div>\n", fout);
	fputws(L"\t\t\t\t\t<div class=\"InfoGroup\">Mô tả</div>\n", fout);
	fputws(L"\t\t\t\t\t<div class=\"Description\">\n", fout);
	fwprintf(fout, L"                            %ls.", sv[i].MoTa);
	fputws(L"\t\t\t\t\t</div>\n", fout);
	fputws(L"\n",fout);
	fputws(L"\t\t\t\t\t</div>\n", fout);
	fputws(L"\t\t\t\t</div>\n", fout);
	fputws(L"\t\t\t</div>\n", fout);
	fputws(L"\n", fout);
	fputws(L"\t\t\t<!-- Begin Layout Footer -->\n", fout);
	fputws(L"\t\t\t<div class=\"Layout_Footer\">\n", fout);
	fputws(L"\t\t\t\t<div class=\"divCopyright\">\n", fout);
	fputws(L"\t\t\t\t\t<br />\n", fout);
	fputws(L"\t\t\t\t\t<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n", fout);
	fputws(L"\t\t\t\t\t<br />\n", fout);
	fputws(L"\t\t\t\t\t@2018</br>\n", fout);
	fputws(L"\t\t\t\t\tĐồ án giữ kỳ</br>\n", fout);
	fputws(L"\t\t\t\t\tKỹ thuật lập trình</br>\n", fout);
	fputws(L"\t\t\t\t\tTH2018/04</br>\n", fout);
	fputws(L"\t\t\t\t1712879 - Phan Văn Tuấn</br>", fout);
	fputws(L"\t\t\t\t</div>\n", fout);
	fputws(L"\t\t\t</div>\n", fout);
	fputws(L"\t\t\t<!-- End Layout Footer -->\n", fout);
	fputws(L"\t\t</div>\n", fout);
	fputws(L"\t</body>\n", fout);
	fputws(L"</html>\n", fout);
}
void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT); 
	_setmode(_fileno(stdin), _O_U16TEXT);
	SinhVien* sv; wchar_t* TenFile;
	FILE* fin = _wfopen(L"file.csv", L"r, ccs=UTF-8");
	if (!fin)
	{
		wprintf(L"Không thể đọc file file.csv\n");
	}
	else
	{
		int n = DemSoDong(fin);
		sv = new SinhVien[n];
		fseek(fin, 2L, SEEK_SET);
		DocFileCSV(fin, sv, n);
		XuatThongTin(sv, n);
		for (int i = 0; i < n; i++)
		{
			TenFile = NoiChuoi(sv[i].MSSV, L".htm");
			FILE* fout = _wfopen(TenFile, L"w, ccs=UTF-8");
			GhiFileHTML(fout, sv, i);
			
			fclose(fout);
		}
		delete[] sv;
		fclose(fin);
	}
	wprintf(L"Chương trình kết thúc.\n");
}