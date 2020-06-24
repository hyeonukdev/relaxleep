var http = require('http');
var url = require('url');
var exec = require('child_process').exec; // 시스템 명령을 동작시키기 위한 객체 선언.
var cmd = '';

http.createServer(function(req,res){

	var content = url.parse(req.url).pathname;//입력받은 url의 pathname을 읽어들입니다.

	content = content.replace(/%20/g,' ');//문자열 내의 %20을 뛰어쓰기로 바꿉니다.(pathname에서띄어쓰기는 %20)

	content = content.substr(1,content.length);//첫번째문자를 제외한 나머지 글자를 저장(첫번째 글자는 '/'입니다.
			
	cmd = content;
	
	exec(cmd);
	
	res.writeHead(302, {"Location" : "http://192.168.43.100"});
	
	res.end();//html태그를 닫으면서 종료

}).listen(1234, function(){
	console.log('server running');
});//1234 포트를 연다.