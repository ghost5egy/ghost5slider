$( window ).load(function(){ 
$(".yasaslider #1").show("fade",500);
$(".yasaslider #1").delay(5500).hide("slide",{direction:"right"},500);

var sc = $(".yasaslider img").size();
var count = 2;
setInterval(function (){
$(".yasaslider #"+count).show("slide",{direction:"right"},500);
$(".yasaslider #"+count).delay(5500).hide("slide",{direction:"left"},500);

if(count == sc){
count = 1;
}else{
count = count +1;
}
},6500);
});