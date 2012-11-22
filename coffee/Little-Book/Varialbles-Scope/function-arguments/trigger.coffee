trigger = (events...) ->
  events.splice(1, 0, this)
  this.constructor.trigger.apply(events)
