//Object kết quà
var ketqua = document.getElementById('ketqua');

var end = false;

//Đổi dấu
var doi_dau = false;

//vừa bấm phép tinh ?
var doi_phep_tinh = false;

var phep_tinh_cu = '';

//Số phép tính ưu tiên tìm thấy
var uu_tien = 0;

//Mảng ghi nhớ các số hạng
var mang_so_index = 0;
var mang_so = new Array();

//Mảng ghi nhớ các phép tính
var mang_pt_index = 0;
var mang_pt = new Array();

//Nd kết quả
var str_ketqua = '';

 //phím mới
 var phim_moi = '';

//Cài đặt sự kiện
function ClickButton(obj){

    if(end){
        ketqua.value = '';
        end = false;
    }
    //chuỗi hiện tại của kết quả
    if(str_ketqua == '' && phim_moi == '')
    {
        str_ketqua = ketqua.value;
    }
    if(str_ketqua == 0)
    {
        str_ketqua = '';
    }

    var type = obj.innerHTML;
    //Nhóm số
    if( type == 0 ||
        type == 1 ||
        type == 2 ||
        type == 3 ||
        type == 4 ||
        type == 5 ||
        type == 6 ||
        type == 7 ||
        type == 8 ||
        type == 9 ||
        type == '+/-' ||
        type == '.')
    {
        doi_phep_tinh = false;
        //đổi dấu
        if(type == '+/-'){
            if(doi_dau){
                doi_dau = false;
                phim_moi = phim_moi.substring(1);
            }
            else
            {
                doi_dau = true;
                phim_moi = '-' + phim_moi;
            }
        }
        //số
        else
        {
            phim_moi += type;
        }
        //thay đổi hiện thị
        ketqua.value = str_ketqua + phim_moi;
    }
    //nhóm phép tính (+ - * /)
    else if ( type == '+'|| type == '-'|| type == 'x'|| type == '/')
    {
        if(doi_phep_tinh){
            if((phep_tinh_cu == 'x' || phep_tinh_cu == '/') && (type == '+' || type == '-')){
                uu_tien --;
            }
            else if((phep_tinh_cu == '+' || phep_tinh_cu == '-') && (type == 'x' || type == '/'))
            {
                uu_tien++;
            }
            mang_pt[mang_pt_index - 1] = type;
            ketqua.value = ketqua.value.substring(0,ketqua.value.length - 1) + type;
        }
        else{
            phep_tinh_cu = type;
            mang_so[mang_so_index] = parseFloat(phim_moi);
            mang_so_index ++;

            mang_pt[mang_pt_index] = type;
            mang_pt_index ++;

            ketqua.value = ketqua.value + type;
            if(type == 'x' || type == '/'){
                uu_tien ++;
            }
        }
        doi_phep_tinh = true;
        str_ketqua = '';
        phim_moi = '';
    }
    else if(type == '=' || type == '%')
    {
        end = true;
        if(phim_moi != ''){
            mang_so[mang_so_index] = parseFloat(phim_moi);
        }
        if(type == '='){
            GetValue();
        }
        else //tính %
        {
            GetPercent();
        } 
        str_ketqua = '';
        phim_moi = '';
        mang_so = new Array();
        mang_pt = new Array();
        mang_pt_index = 0;
        mang_so_index = 0;
        uu_tien = 0;
    }
    else if(type == 'CE'){
        phim_moi = '';
        ketqua.value = str_ketqua + phim_moi;
    }
    else
    {
        if(phim_moi.length > 1){
            phim_moi = phim_moi.substring(0, phim_moi.length.length -1);
        }
        else
        {
            phim_moi = '';
        }
        ketqua.value = str_ketqua + phim_moi;
    }
}
// tính %
function GetPercent(){
    mang_pt_index --;
    if(mang_so_index !=1 || mang_so[1] ==0){
        ketqua.value = "0";
    }
    else if(mang_pt_index !=0){
        ketqua.value ="0";
    }
    else if(mang_pt[0] !='/'){
        ketqua.value = "0";
    }
    else{
        var _kq = mang_so[0] / mang_so[1] * 100;
        ketqua.value = _kq;
    }
    str_ketqua = '';
    phim_moi = '';
    mang_so = new Array();
    mang_pt = new Array();
    mang_pt_index = 0;
    mang_so_index = 0;
}

function GetValue(){
    mang_pt_index--;
    while(uu_tien>0){
        for(var index = 0; index <= mang_pt_index; index ++){
            if(mang_pt[index] == 'x' || mang_pt[index] == '/'){
                var sh1 = mang_so[index];
                var sh2 = mang_so[index + 1];
                var kqt = 0;
                if (mang_pt[index] == 'x'){
                    var kqt = sh1 * sh2 ;
                }
                else if(sh2 == 0){
                    ketqua.value = '0';
                }
                else{
                    kqt = sh1 / sh2;
                }
                mang_so[index] = kqt;

                for (var new_index = index + 1; new_index <mang_so_index; new_index ++){
                    mang_so[new_index] = mang_so[new_index + 1];
                }
                mang_so_index --;

                for (var new_index = index; new_index < mang_pt_index; new_index ++){
                    mang_pt[new_index] = mang_pt[new_index + 1];
                }
                mang_pt_index --;

                uu_tien --;

                break;

            }
        }
    }
    //phép tính thường
    while(mang_so_index > 0){
        var sh1 = mang_so[0];
        var sh2 = mang_so[1];
        var kqt = 0;
        if(mang_pt[0] == '+'){
            kqt = sh1 + sh2;
        }
        else{
            kqt = sh1 - sh2;
        }
        mang_so[0] = kqt;

        for (var new_index = 1; new_index <mang_so_index; new_index ++){
            mang_so[new_index] = mang_so[new_index + 1];
        }
        mang_so_index --;

        for (var new_index = 0; new_index < mang_pt_index; new_index ++){
            mang_pt[new_index] = mang_pt[new_index + 1];
        }
        mang_pt_index --;
    }
    ketqua.value = mang_so[0];
}