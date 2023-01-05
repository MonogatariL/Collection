const MassageItem = {
  props: ['news'],
  template:
    '<a href="#" class="message-nav">' +
    '<img v-bind:src="news.imgUrl" alt="news.title" width="100%" height="100%">' +
    '<div>{{ news.title }}</div>' +
    '</a>'
}

const VmMessageList = new Vue({
  el: '.message-list',
  data: {
    newsGroup: [
      {
        imgUrl: './img/v2-d95ab6d0a993ac0d7cab8fad8ffd4429.jpg',
        title: '纹眉有哪些健康风险?'
      },
      {
        imgUrl: './img/v2-10507727e62229e5e7d7e7a1a8a4db61.jpg',
        title: '免疫疗法治疗癌症靠谱吗？'
      },
      {
        imgUrl: './img/v2-143dea3ebd0a714fd3ee84c50475b7da.jpg',
        title: '《超级马力欧 64》在游戏史上的地位如何？'
      },
      {
        imgUrl: './img/v2-404b3e371ea0a8a9a8235a83a2dfd833.jpg',
        title: '有哪些剑术上的事实，没有一定武学知识的人不会相信？'
      },
      {
        imgUrl: './img/v2-528de3eea2cfabca569f2227bb4a6776.jpg',
        title: '如何通过玩游戏拯救地球？'
      },
      {
        imgUrl: './img/v2-901e6b4f4effe5b7c71aee3dda151301.jpg',
        title: '瞎扯 · 如何正确地吐槽'
      },
      {
        imgUrl: './img/v2-9ee58356a0b3aa3ec9efff34fd5e6f3f.jpg',
        title: '二本学校的学生想考研到 211、985 学校现实吗？'
      },
      {
        imgUrl: './img/v2-a9823c0306f598d873c658c2f2818e7c.jpg',
        title: '科学家是如何判断两个现象之间的因果关系的？'
      },
      {
        imgUrl: './img/v2-bf5a0f852005e019651d37c8b59f58f0.jpg',
        title: '为什么鹦鹉螺可以数亿年来没有太大的外观上的变化？'
      },
      {
        imgUrl: './img/v2-d074516f51738af071acc1ddcf374d95.jpg',
        title: '中国有可能实现编剧中心制吗？'
      },
      {
        imgUrl: './img/v2-e2093ec965330bb01db9a3d9e9d90d87.jpg',
        title: '电商的空调商品标题里都有哪些猫腻？'
      },
      {
        imgUrl: './img/v2-f5106153eb885291b93586245b4f432a.jpg',
        title: '如何纯手工自己打造一款机械表?'
      },
      {
        imgUrl: './img/v2-1.jpg',
        title: '夸一朵花会让它长得更好吗？'
      },
      {
        imgUrl: './img/v2-2.jpg',
        title: '欧洲游戏产业的发展状况如何？'
      },
      {
        imgUrl: './img/v2-3.jpg',
        title: '跑步和游泳哪种健身方式更好？'
      },
      {
        imgUrl: './img/v2-zhuangyuan.jpg',
        title: '清华北大抢状元的意义何在？'
      },
      {
        imgUrl: './img/v2-tucao.jpg',
        title: '瞎扯 · 如何正确地吐槽'
      },
      {
        imgUrl: './img/v2-cat.jpg',
        title: '帮小猫咪洗澡时需要注意哪些问题？'
      },
      {
        imgUrl: './img/v2-pikaqiu.jpg',
        title: '皮卡丘有几个手指头？'
      },
      {
        imgUrl: './img/v2-pugongying.jpg',
        title: '蒲公英真的对身体有益吗？'
      },
      {
        imgUrl: './img/v2-zuijiu.jpg',
        title: '一次醉酒会持续影响大脑功能 6 周吗？'
      },
      {
        imgUrl: './img/v2-rain.jpg',
        title: '为什么雨水落下来不会砸死人？'
      },
      {
        imgUrl: './img/v2-camp.jpg',
        title: '新手如何露营以及需要注意的地方？'
      },
      {
        imgUrl: './img/v2-highspeed.jpg',
        title: '中国有哪些「值得特地走一趟」的高速公路？'
      }
    ]
  },
  components: {
    item: MassageItem
  }
})