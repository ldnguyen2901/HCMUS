var a = prompt("MSSV", "Nhập mã số sinh viên");
var b = prompt("Họ tên", "Nhập họ tên sinh viên");
var c = prompt("Lớp", "Nhập lớp");
if (a != null && b != null && c != null) {
  document.getElementById("a").innerHTML = a;
  document.getElementById("b").innerHTML = b;
  document.getElementById("c").innerHTML = c;
}

  