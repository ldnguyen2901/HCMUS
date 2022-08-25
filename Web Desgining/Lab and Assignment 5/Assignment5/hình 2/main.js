var Products = [
    {
      ten: "CPU",
      soluongco: 10,
      dongia: 100,
    },
    {
      ten: "RAM",
      soluongco: 10,
      dongia: 50,
    },
    {
      ten: "HDD",
      soluongco: 10,
      dongia: 80,
    },
  ];
  
  getTable(Products);
  
  function getTable(data) {
    var table = document.getElementById("my-table");
  
    for (var i = 0; i < data.length; i++) {
      var row = `<tr>
          <td>${[i + 1]}</td>
          <td>${data[i].ten}</td>
          <td>${data[i].soluongco}</td>
          <td>${data[i].dongia}</td>
          <td><input type="checkbox" name="game" onclick="myFun(this)"class="checks" onchange="document.getElementById('qty').disabled = !this.checked;" value="${
            data[i].dongia
          }"></td>
          </tr>`;
      table.innerHTML += row;
    }
  }
  
  function myFun(checkbox) {
    var checkboxes = document.getElementsByName('game')
    checkboxes.forEach((item) => {
      if (item !== checkbox) item.checked =  false
    })
  }
  
  console.log(Products.length);
  
  var btnShow = document.querySelector("button");
  var tong = document.querySelector("span");
  
  btnShow.addEventListener("click", () => {
    let qty1 = Number(document.getElementById("qty").value);
    let vat = document.getElementById("vat");
    let checkbox = document.querySelector('input[class="checks"]:checked');
  
    let checkbox1 = Number(checkbox.value);
  
    if (vat.checked === true) {
      return (tong.innerText = qty1 * checkbox1 + qty1 * checkbox1 * 0.1);
    }
    console.log(typeof checkbox1);
  
    tong.innerText = checkbox.value * qty1;
  });
  