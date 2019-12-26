# 멀티캠퍼스 Linux class 시작

## 1일차 수업 환경설정 
- 리눅스 버전 : CentOS-7.0-1406-x86_64-DVD
- 영어 언어 추가, 표준 파티션에 새마운트 지점을 추가하였음. swap(하드디스크를 메모리처럼 사용) 지점에 2G, 마운트지점 /, 용량은 x

- 해당 과정에서는 실습을 위해서 관련 업데이트를 막았음.
- cd /etc/yum.repos.d/ 폴더에서 진행
- 아직 vim에 대해 배우지 않았으므로 gedit을 사용하였음
- gedit CentOS-Base. repo, gedit CentOS-Sources. repo에서 update파트 삭제
- CentOS-Base.repo의 백업파일을 만든 뒤  repo.~파일들을 삭제해 주었음.
- 이후 wget http://download.hanbit.co.kr/centos/7/CentOS-Base.repo로 파일설치.
- 파일권한을 644로 줌. 이후 yum clean all


- cd/etc/sysconfig/network-scripts/
- ifcfg-eno16777736 수정
- BOOTPROTO="none"
- IPADDR=192.168.111.101
- NETMASK=255.255.255.0
- GATEWAY=192.168.111.2
- DNS1=192.168.111.2
- 이후 systemctl restart network 입력해서 세팅완료.

- vim/etc/sysconfig/selinux에서 selinux를 disable로 바꿔서 보안을 약화시켜줌. 이는 테스트 환경에서의 접속을 용이하게 하기 위함임. 이후 reboot

***

### clone 만들기.
- clone을 만들기 위해 서버가 설치된 폴더를 복사, 붙여넣기로 만듬.
    - 복사한 폴더에 들어가서 configurationfile을 켠 후 이 중 displayName = "server2"로 바꿔줌.
    - 이후 vmware에서 open a virtual machine으로 접근하여 이를 등록해여 줌.
    - 다음에 setting -> network adapter에서 mac-address를 바꿈.
    - 바꾼 mac-address를 복사해둬야함
    - 실행할 때 move옵션을 선택하여야 함.
    - 이후 ifcfg-eno16777736에서 mac address 파트를 바뀐 mac address로 바꾸고, ip주소도 바꿔주어야 함. 변경 후에는 항상 systemctl restart network

    - 예시=> hostnamectl set-hostname server2  와 같이 hostname을 설정 가능
    - hostname을 사용하기 위해서는 /etc/hosts의 내용에 예시) 192.168.111.101 server1 192.168.111.102 server2 와 같이 이름을 등록해주어야 함. 

***

## 2일차

- 명령어
  - history -c : 히스토리 내역 삭제
  - su : 유저 변경
  - su - : 환경까지 변경.
  - rm : 파일을 삭제하는 명령어  폴더를 삭제하려면 뒤에 -r 태그를 붙여주어야 한다
  - man [명령어] : 명령어에 대한 다양한 옵션들을 확인할 수 있음
  - mount  : 연결된 장치들을 확인할 수 있음
    - 장치를 다른 파일에 연결해줄 수도 있음 ex) mount /dev/cdrom /root/mycdrom
  - umount [경로 : ex) /dev/cdrom]: unmount하는 명령어
  - kill [pid] : 해당 pid를 가진 프로세서를 종료함
  - useradd [유저] : 유저를 추가할 수 있다. 이후 passwd를 이용하여 암호를 설정할 수 있음.
    - useradd -p 비밀번호 [유저] 를 통해 한번에 설정할 수도 있음.

***

- vim 관련 명령어
  - i :  입력모드						I : 현재 커서 줄의 맨 앞에서부터 입력
  - a : (append) 현재 커서의 뒤에 입력	A : 현재 커서 줄의 맨 마지막부터 입력
  - o : 현재 커서의 다음 줄에 입력         O : 현재 커서의 이전 줄에 입력
  - s : 현재 커서 위치의 한 글자를 지우고 입력        S : 현재 커서의 한 줄을 지우고 입력
  - ctrl + f : 다음 화면으로 이동 (page down)
  - ctrl + b : 이전 화면으로 이동(page up)
  - $ : 현재 행의 마지막으로 이동 (end)
  - ^ : 현재 행의 처음으로 이동
  - gg : 제일 첫 행으로 이동
  - G : 제일 끝 행으로 이동
  - 숫자 G : 해당 숫자의 행으로 이동
  -  :숫자 : 해당 숫자의 행으로 이동
  - x : 현재 커서가 위치한 글자 삭제  X : 현재 커서가 위치한 앞 글자 삭제
  - dd : 현재 커서의 행 삭제 
  - 숫자 dd : 현재 커서부터 숫자만큼의 행 삭제
  - yy : 현재 커서가 있는 행을 복사
  - 숫자 yy : 현재 커서부터 숫자만큼의 행을 복사
  - p 복사한 내용을 현재 행 이후에 붙여넣기     P : 복사한 내용을 현재 행 이전에 붙여넣기
  - /문자열 : 해당 문자열을 찾음.  ====> n키를 누르면 다음 문자로 이동 



## 3일차



mc와 java에 대한 설치를 진행하였습니다. 설치는 rpm, tar, yum 세 가지 방식을 사용하여 진행하였습니다.



 ln -s /etc/eclipse/usr/bin/eclipse eclipse -> /etc/eclipse를  /usr/bin 디렉토리에 soft link

ln -s /etc/jdk1.8.0/bin/java java -> /etc/jdk1.8.0을 /bin 디렉토리에 soft link.   ==> 만들고자 하는 폴더에서 하기





 	1. 심볼릭 링크에 대한 학습
     - ex) ln(링크) ~/mc-4.8.7.8.e17.x86_64(예시파일).rpm mch(만들어줄 링크 이름).rpm(하드링크)
     - ex) ln(링크) -s(소프트링크) ~/mc-4.8.7.8.e17.x86_64(예시파일).rpm mcs(만들어줄 링크 이름).rpm 



2. rpm 을 통한 설치
   - rpm -Uvh <파일>.rpm
3. tar를 통한 설치
   - tar -xvf <파일>
   - 하나로 묶기 tar -cvf <만들어질 파일> <압축 대상 파일> (예를 들면 : tar -cvf vitest.tar vitest) => 압축을 위해 파일을 묶는 것
   - 압축 :  xz (tar 파일)vitest.tar
   - 압축 해제 : tar xfz <대상 파일이름 .tar.gz> 압축을 풀고 tar도 푼다. 그러나 최근에는 -xvf로도 다 풀린다.
4. yum을 통한 설치
   	- yum -y



5. 압축 관련 (vitest.tar 파일을 압축한다고 가정)

   -  tar -cvf vitest.tar vitest 

   - gzip vitest.tar
   - bzip2 vitest.tar
   - zip vitest.tar.zip vitest.tar



6. 검색 관련
   - find <찾을 대상 폴더> -name(이름을 기반으로) "*.conf" -perm 644(권한이 644) -size(사이즈가) -3k (3k이하) -user(유저가)
   - find /root -perm 644 -size -1k -exec(실행한다) ls -l {앞에서 find로 뽑아온 대상} \; 
     - 결과적으로 find의 결과 하나 하나에 ls -l을 실행한다는 뜻임.

7. 예약설정
   - /etc 밑에 crontab 파일을 이용해서 예약을 설정할 수 있음.