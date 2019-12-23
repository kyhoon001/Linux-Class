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



- clone 만들기.
- clone을 만들기 위해 서버가 설치된 폴더를 복사, 붙여넣기로 만듬.
- 복사한 폴더에 들어가서 configurationfile을 켠 후 이 중 displayName = "server2"로 바꿔줌.
- 이후 vmware에서 open a virtual machine으로 접근하여 이를 등록해여 줌.
- 다음에 setting -> network adapter에서 mac-address를 바꿈.
` 바꾼 mac-address를 복사해둬야함
- 실행할 때 move옵션을 선택하여야 함.

- 이후 ifcfg-eno16777736에서 mac address 파트를 바뀐 mac address로 바꾸고, ip주소도 바꿔주어야 함. 변경 후에는 항상 systemctl restart network

- 예시=> hostnamectl set-hostname server2  와 같이 hostname을 설정 가능
- hostname을 사용하기 위해서는 /etc/hosts의 내용에 예시) 192.168.111.101 server1 192.168.111.102 server2 와 같이 이름을 등록해주어야 함. 

-       테스트